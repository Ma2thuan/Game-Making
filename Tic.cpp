#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>

void NguoiChoimove2();


enum  state
{
	LOADING = 0, MENU, WHO , SINGLEPLAYER, TWOPLAYER, INFORMATION, GAMEOVER, EXIT
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

	printf("\n\n\t\t\t\t\t\t    TIC-TAC-TOE\n\n\n");

	printf("\t\t\t\t\t              |     |             \n");
	printf("\t\t\t\t\t          %c   |  %c  |  %c  \n", TrangThai(b[1]), TrangThai(b[2]), TrangThai(b[3]));

	printf("\t\t\t\t\t         _____|_____|_____  \n");
	printf("\t\t\t\t\t              |     |    \n");

	printf("\t\t\t\t\t          %c   |  %c  |  %c \n", TrangThai(b[4]), TrangThai(b[5]), TrangThai(b[6]));

	printf("\t\t\t\t\t         _____|_____|_____\n");
	printf("\t\t\t\t\t              |     |    \n");

	printf("\t\t\t\t\t          %c   |  %c  |  %c \n", TrangThai(b[7]), TrangThai(b[8]), TrangThai(b[9]));
}

int DieuKien(int square[10]) {

	int  DieuKienWin[8][3] = { {1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7} };
	
	for (int i = 0; i < 8; ++i) {
		if (square[DieuKienWin[i][0]] != 0 &&
			square[DieuKienWin[i][0]] == square[DieuKienWin[i][1]] &&
			square[DieuKienWin[i][1]] == square[DieuKienWin[i][2]])
			return square[DieuKienWin[i][1]];
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

//NGuoi Choi may tinh

void NguoiChoimove(int square[10]) {

	int move = 0;
	do {
		printf("\nNhap buoc di cua nguoi choi 2  : ([1..9]): ");
		scanf("%d", &move);
		
		printf("\n");
	} while (move > 9 || move < 1 || square[move] != 0);
	square[move] = -1;
}

//Nguoi choi 2


void NguoiChoimove2(int square[10],char Ten2[]) {

	int move = 0;
	do {
		printf("\nNhap buoc di cua nguoi %s  : ([1..9]): ",Ten2);
		scanf("%d", &move);
		
		printf("\n");
	} while (move > 9 || move < 1 || square[move] != 0);
	square[move] = -1;
}

// Nguoi Choi 1 

void NguoiChoimove1(int square[10],char Ten1[]) {

	int move = 0;
	do {
		printf("\nNhap buoc di cua nguoi choi %s : ([1..9]): ",Ten1);
		scanf("%d", &move);
		printf("\n");
	} while (move > 9 || move < 1 || square[move] != 0);
	square[move] = 1;

}

//Man hinh load

void loading()
{

	// Su dung gia tri ASCII de tao ra ky hieu
	// loading bar

	char a = 177, b = 219;
	int load = 1000;
	int c = 90;
	printf("\n\n\n\n");
	printf("\n\n\n\n\t\t\t Loading X and O.....\n\n");
	printf("\t\t\t\t\t");

	// In ra thanh load
	for (int i = 0; i < 26; i++)
		printf("%c", a);

	// Dua con tro ve vi tri dau thanh load

	printf("\r");
	printf("\t\t\t\t\t");

	// Nhich thanh load
	for (int i = 0; i < 26; i++) {
		if (c > 98)
			c = 90;
				printf("%c", b);
		if (load > 50)
			load = load - 50;
		// Thoi gian load giam dan
		Sleep(load);
	}
	printf("\n\n\n\t\t\t\t\tPress any key to continue!!");
	getchar();
	system("cls");
	state = MENU;
}





// Man hinh chinh cua game

void MotNguoiChoi() {

	int square[10] = { 0,0,0,0,0,0,0,0,0,0 };

	printf("\n\n\t\t\t\t\t\tAI : (O) VS Player : (X)\n\n\n\n Ban muon di (1)st hay (2)nd : ");
	int LuotDi = 0;
	scanf("%d", &LuotDi);
	printf("\n");

	system("cls");
	getchar();

	for (int turn = 0; turn < 9 && DieuKien(square) == 0; ++turn) {
		if ((turn + LuotDi) % 2 == 0){
		
			AImove(square);
			system ("cls");
}
		else {
			BangChoi(square);
			NguoiChoimove(square);
		}
	}
	switch (DieuKien(square)) {
	case 0:
		BangChoi(square);
		printf("\n\n\t\t\t\t\t\tHoa -_-\n");
		printf("\n\n\n\t\t\t\t\tPress any key to continue!!");
		
		getchar(); getchar();
		system("cls");
		state = GAMEOVER;
		break;
	case 1:
		BangChoi(square);
		printf("\n\n\t\t\t\t\t\tThua roi ay! ;))\n");
		printf("\n\n\n\t\t\t\t\tPress any key to continue!!");
		getchar(); getchar();
		system("cls");
		state = GAMEOVER;
		break;
	case -1:
		printf("\n\n\t\t\t\t\t\tCheat roi chu ji :)))\n");
		printf("\n\n\n\t\t\t\t\tPress any key to continue!!");
		getchar(); getchar();
		system("cls");
		state = GAMEOVER;
		break;
	}
}
// 2 nguoi choi

void HaiNguoiChoi() {

	int square[10] = { 0,0,0,0,0,0,0,0,0,0 };
    char Ten1[30] , Ten2[30];

	getchar();
		
	printf("\n\n\t\t\t\t\t\tNhap ten nguoi choi 1 : ");
	//fgets (Ten1, 30, stdin); Ten1[strlen(Ten1) - 1] = '\0';
	scanf("%s",&Ten1);
	fflush(stdin);
	printf("\n\n\t\t\t\t\t\tNhap ten nguoi choi 2 : ");
	//fgets(Ten2, 30, stdin); Ten2[strlen(Ten2) - 1] = '\0';
	scanf("%s",&Ten2);

	printf("\n\n\t\t\t\t\t\t%s : (O) VS %s : (X)\n\n\n\n %s muon di (1)st hay (2)nd : ",Ten1,Ten2,Ten1);
	int LuotDi = 0;
	scanf("%d", &LuotDi);
	printf("\n");

	system("cls");

	for (int turn = 0; turn < 9 && DieuKien(square) == 0; ++turn) {
		if ((turn + LuotDi) % 2 == 0) {
			BangChoi(square);
			NguoiChoimove2(square, Ten2);
			
		}
		else {
			BangChoi(square);
			NguoiChoimove1(square, Ten1);
			
		}
	}
	switch (DieuKien(square)) {
	case 0:
		BangChoi(square);
		printf("\n\n\t\t\t\t\t\tHoa -_-\n");
		printf("\n\n\n\t\t\t\t\tPress any key to continue!!");

		getchar(); getchar();
		system("cls");
		state = GAMEOVER;
		break;
	case 1:
		BangChoi(square);
		printf("\n\n\t\t\t\t\t\t%s da gianh chien thang \n", Ten1);
		printf("\n\n\n\t\t\t\t\tPress any key to continue!!");
		getchar(); getchar();
		system("cls");
		state = GAMEOVER;
		break;
	case -1:
		BangChoi(square);
		printf("\n\n\t\t\t\t\t\t%s da gianh chien thang \n", Ten2);
		printf("\n\n\n\t\t\t\t\tPress any key to continue!!");
		getchar(); getchar();
		system("cls");
		state = GAMEOVER;
		break;
	}
}



//Menu cua tro choi

void menu() {
	int x = 0;
	printf("\n\n\t\t\t\t\t    T I C  -- T A C -- T O E -- G A M E\n\n\n");
	printf("\t\t\t\t\t\t\t1.Single Player\n\n");
	printf("\t\t\t\t\t\t\t2.Two Player \n\n");
	printf("\t\t\t\t\t\t\t3.Rules\n\n");
	printf("\t\t\t\t\t\t\t4.Exit\n\n\n\n\n");

	printf("\t\t\t\t\t       Choose : "); scanf("%d", &x);
	switch (x) {
	case 1:
		system("cls");
		state = SINGLEPLAYER;
		break;

	case 2:
		system("cls");
		state = TWOPLAYER;
		break;

	case 3:
		system("cls");
		state = INFORMATION;
		break;
	case 4:
		system("cls");
		state = EXIT;
		break;
	}



}


// Luat le game

void info() {
	printf("\n1. The game is played on a grid that's 3 squares by 3 squares.\n");
	printf("\n2. You are X and the computer  is O. Players take turns putting their marks in empty squares.\n");
	printf("\n3. The first player to get 3 of her or his marks in a row (up, down, across, or diagonally) is the winner.\n");
	printf("\n4. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie.\n");
	printf("\nHere how the board look like !!\n");

	printf("\t\t\t\t\t              |     |             \n");
	printf("\t\t\t\t\t          1   |  2  |  3  \n");

	printf("\t\t\t\t\t         _____|_____|_____  \n");
	printf("\t\t\t\t\t              |     |    \n");

	printf("\t\t\t\t\t          4   |  5  | 6 \n");

	printf("\t\t\t\t\t         _____|_____|_____\n");
	printf("\t\t\t\t\t              |     |    \n");

	printf("\t\t\t\t\t          7   |  8  |  9 \n");


	printf("\nPress any key to continue!!\n");


	getchar(); getchar();
	system("cls");
	state = MENU;
}


// Man hinh ket thuc van choi

void over() {
	int x = 0;
	printf("\n\t\t\t\t\t\t Would you like to play again!!\n\n");
	printf("\n\t\t\t\t\t\t1.Choi chu!!\n\n");
	printf("\n\t\t\t\t\t\t2.Thoiiiiiii!\n\n");

	printf("\t\t\t\t       Choose : ");
	scanf("%d", &x);

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

	state = MENU;

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
		case SINGLEPLAYER:
			MotNguoiChoi();
			break;

		case TWOPLAYER:
			HaiNguoiChoi();
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
