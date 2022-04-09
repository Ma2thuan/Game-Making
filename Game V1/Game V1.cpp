#include <stdio.h>


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

void BangChoi( int b[10]) {
	printf(" %c | %c | %c\n", TrangThai(b[1]), TrangThai(b[2]), TrangThai(b[3]));
	printf("---+---+---\n");
	printf(" %c | %c | %c\n", TrangThai(b[4]), TrangThai(b[5]), TrangThai(b[6]));
	printf("---+---+---\n");
	printf(" %c | %c | %c\n", TrangThai(b[7]), TrangThai(b[8]), TrangThai(b[9]));
}


int DieuKien(int square[10] ) {

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


	int move  = -1;
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












int main() {
	int square[10] = { 0,0,0,0,0,0,0,0,0,0 };
	printf_s("AI : O VS Player : X\n Ban muon di (1)st hay (2)nd");
	int LuotDi = 0;
	scanf_s("%d", &LuotDi);
	printf_s("\n");


}