#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>

enum  state
{
	LOADING = 0, MENU , INGAME, INFORMATION, GAMEOVER, EXIT
}state;


char TrangThai(int i) {
	switch (i) {
	case -1:
		return 'X';
	case 0:
		return ' ';
	case 1:
		return 'O';
	}
}

//1 là AI || -1 la player

void BangChoi(int b[10]) {

	printf_s("\n\n\t\t\t\t\t\t    TIC-TAC-TOE\n\n\n");

	printf_s("\t\t\t\t\t              |     |             \n");
	printf_s("\t\t\t\t\t          %c   |  %c  |  %c  \n", TrangThai(b[1]), TrangThai(b[2]), TrangThai(b[3]));

	printf_s("\t\t\t\t\t         _____|_____|_____  \n");
	printf_s("\t\t\t\t\t              |     |    \n");

	printf_s("\t\t\t\t\t          %c   |  %c  |  %c \n", TrangThai(b[4]), TrangThai(b[5]), TrangThai(b[6]));

	printf_s("\t\t\t\t\t         _____|_____|_____\n");
	printf_s("\t\t\t\t\t              |     |    \n");

	printf_s("\t\t\t\t\t          %c   |  %c  |  %c \n", TrangThai(b[7]), TrangThai(b[8]), TrangThai(b[9]));
}

int DieuKien(int square[10]) {

	unsigned DieuKienWin[8][3] = { {1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7} };
	//Unsigned luon tra ve gia tri duong (+)
	for (int i = 0; i < 8; ++i) {
		if (square[DieuKienWin[i][0]] != 0 &&
			square[DieuKienWin[i][0]] == square[DieuKienWin[i][1]] &&
			square[DieuKienWin[i][0]] == square[DieuKienWin[i][2]])
			return square[DieuKienWin[i][2]];
	}
	return 0;
}


int Minimax(int square[10], int player) {
	//Ktra xem nguoi choi win chua
	int NguoiThang = DieuKien(square);
	if (NguoiThang != 0) return NguoiThang * player;


	int move = -1;
	int score = -2;


	for (int i = 1; i < 10; ++i) {
		if (square[i] == 0) {
			square[i] = player;//Thu nuoc di
			int thisScore = -Minimax(square, player * -1);
			if (thisScore > score) {
				score = thisScore;
				move = i;
			}//move 
			square[i] = 0;//Reset nuoc di
		}
	}
	if (move == -1) return 0;
	return score;
}

void AImove(int square[10]) {

	int move = -1;
	int score = -2;

	for (int i = 1; i < 10; ++i) {
		if (square[i] == 0) {
			square[i] = 1;
			int tempScore = -Minimax(square, -1);
			square[i] = 0;
			if (tempScore > score) {
				score = tempScore;
				move = i;
			}
		}
	}
	//Lay buoc di hop ly nhat
	square[move] = 1;
}



void NguoiChoimove(int square[10]) {

	int move = 0;
	do {
		printf("\nNhap buoc di : ([1..9]): ");
		scanf_s("%d", &move);
		printf("\n");
	} while (move > 9 || move < 1 || square[move] != 0);
	square[move] = -1;

}

//Man hinh load

void loading()
{

	// Su dung gia tri ASCII de tao ra ky hieu
	// loading bar

	char a = 177, b = 219;
	int load = 1000;

	printf("\n\n\n\n");
	printf("\n\n\n\n\t\t\t\t\t  Loading X and O.....\n\n");
	printf("\t\t\t\t\t");

	// In ra thanh load
	for (int i = 0; i < 26; i++)
		printf("%c", a);

	// Dua con tro ve vi tri dau thanh load
	
	printf("\r");
	printf("\t\t\t\t\t");

	// Nhich thanh load
	for (int i = 0; i < 26; i++) {
		printf("%c", b);
		if (load > 50)
			load = load - 50;
		// Thoi gian load giam dan
		Sleep(load);
	}
	printf_s("\n\n\n\t\t\t\t\tPress any key to continue!!");
		getchar();
		system("cls");
	state = MENU;
}





// Man hinh chinh cua game

void ingame() {

	int square[10] = { 0,0,0,0,0,0,0,0,0,0 };

	printf_s("\n\n\t\t\t\t\t\tAI : (O) VS Player : (X)\n\n\n\n Ban muon di (1)st hay (2)nd : ");
	int LuotDi = 0;
	scanf_s("%d", &LuotDi);
	printf_s("\n");



	for (int turn = 0; turn < 9 && DieuKien(square) == 0; ++turn) {
		if ((turn + LuotDi) % 2 == 0)
			AImove(square);

		else {
			BangChoi(square);
			NguoiChoimove(square);
		}
	}
	switch (DieuKien(square)) {
	case 0:
		printf("Hoa -_-\n");
		getchar(); getchar();
		system("cls");
		state = GAMEOVER;
		break;
	case 1:
		BangChoi(square);
		printf("Thua roi ay! ;))\n");
		getchar(); getchar();
		system("cls");
		state = GAMEOVER;
		break;
	case -1:
		printf("Cheat roi chu ji :)))\n");
		getchar(); getchar();
		system("cls");
		state = GAMEOVER;
		break;
	}
}


//Menu cua tro choi

void menu() {
	int x = 0;
	printf_s("\n\n\t\t\t\t\t    T I C  -- T A C -- T O E -- G A M E\n\n\n");
	printf_s("\t\t\t\t\t\t\t1.Play\n\n");
	printf_s("\t\t\t\t\t\t\t2.Rules\n\n");
	printf_s("\t\t\t\t\t\t\t3.Exit\n\n\n\n\n");

	printf_s("\t\t\t\t\t       Choose : "); scanf_s("%d", &x);
	switch (x) {
	case 1:
		system("cls");
		state = INGAME;
		break;
	case 2:
		system("cls");
		state = INFORMATION;
		break;
	case 3:
		system("cls");
		state = EXIT;
		break;
	}



}


// Luat le game

void info() {
	printf_s("\n1. The game is played on a grid that's 3 squares by 3 squares.\n");
	printf_s("\n2. You are X and the computer  is O. Players take turns putting their marks in empty squares.\n");
	printf_s("\n3. The first player to get 3 of her or his marks in a row (up, down, across, or diagonally) is the winner.\n");
	printf_s("\n4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.\n");
	printf_s("\nHere how the board look like !!\n");

	printf_s("\t\t\t\t\t              |     |             \n");
	printf_s("\t\t\t\t\t          1   |  2  |  3  \n");

	printf_s("\t\t\t\t\t         _____|_____|_____  \n");
	printf_s("\t\t\t\t\t              |     |    \n");

	printf_s("\t\t\t\t\t          4   |  5  | 6 \n");

	printf_s("\t\t\t\t\t         _____|_____|_____\n");
	printf_s("\t\t\t\t\t              |     |    \n");

	printf_s("\t\t\t\t\t          7   |  8  |  9 \n");


	printf_s("\nPress any key to continue!!\n");


	getchar(); getchar();
	system("cls");
	state = MENU;
}


// Man hinh ket thuc van choi

void over() {
	int x = 0;
	printf_s("\n\t\t\t\t\t\t\Would you like to play again!!\n\n");
	printf_s("\n\t\t\t\t\t\t1.Choi chu!!\n\n");
	printf_s("\n\t\t\t\t\t\t2.Thoiiiiiii!\n\n");

	printf_s("\t\t\t\t       Choose : ");
	scanf_s("%d", &x);

	switch (x) {
	case 1:
		system("cls");
		state = MENU;
		break;
	case 2:
		system("cls");
		state = EXIT;
		break;
	}
}

//Thoat game

void exit() {
	exit(0);
}


int main() {

	state = LOADING;

	while (1)
	{
		switch (state)
		{
		case  LOADING:
			loading();
			break;
		case MENU:
			menu();
			break;
		case INGAME:
			ingame();
			break;

		case INFORMATION:
			info();
			break;

		case GAMEOVER:
			over();
			break;
		case EXIT:
			exit();
			break;
		}

	}

}
