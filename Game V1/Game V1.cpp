#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>




char square[10] = { 'i', '1' ,'2' ,'3' ,'4' ,'5' ,'6' ,'7' ,'8' ,'9' };

void BangChoi(char Ten1[], char Ten2[]) {

	printf_s("\n\n\t\t\t\t\t\t     TIC-TAC-TOE\n\n\n");
	printf_s("\t\t\t\t\t\t %s (X) VS %s (O) \n\n\n", Ten1,Ten2);
	
	printf_s("\t\t\t\t\t              |     |             \n");
	printf_s("\t\t\t\t\t          %c   |  %c  |  %c  \n", square[1], square[2], square[3]);

	printf_s("\t\t\t\t\t         _____|_____|_____  \n");
	printf_s("\t\t\t\t\t              |     |    \n");

	printf_s("\t\t\t\t\t          %c   |  %c  |  %c \n", square[4], square[5], square[6]);

	printf_s("\t\t\t\t\t         _____|_____|_____\n");
	printf_s("\t\t\t\t\t              |     |    \n");

	printf_s("\t\t\t\t\t          %c   |  %c  |  %c \n", square[7], square[8], square[9]);

}

//Ket qua cua tro choi :
//+ 1 la thang 
//+ 0 la hoa 
//+ -1 la tiep tuc

int DieuKien() {
	if (square[1] == square[5] && square[5] == square[9])
		return 1;
	else if (square[3] == square[5] && square[5] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if (square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[3] == square[6] && square[6] == square[9])
		return 1;
	else if (square[7] == square[8] && square[8] == square[9])
		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' &&
		square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else return -1;

}


int main() {

	int NguoiChoi = 1, Danh = 0, i = 0, Chon = 0, z = 0;
	char Mark = 0, Mark2 = 0;
	char Ten1[50], Ten2[50];
	int SoNN = 0;


	printf_s("\nHUMAN VS HUMAN (1) \n");
	printf_s("\nHUAMAN VS AI (2) \n");

	printf_s("\nHay chon che do choi : ");
	scanf_s("%d", &Chon);


	//NGUOI CHOI VS NGUOI CHOI

	if (Chon == 1) {
		printf_s("Nhap ten nguoi choi 1 :   "); fgetc(stdin);
		fgets(Ten1, sizeof(Ten1), stdin); fflush(stdin); Ten1[strlen(Ten1) - 1] = '\0';

		printf_s("Nhap ten nguoi choi 2 :   "); 
		fgets(Ten2, sizeof(Ten2), stdin); Ten2[strlen(Ten2) - 1] = '\0';

		do
		{
			BangChoi(Ten1, Ten2);
			NguoiChoi = (NguoiChoi % 2) ? 1 : 2;
			printf_s("\n\n\n\t\t\t Moi nguoi choi %d chon : ", NguoiChoi);
			scanf_s("%d", &Danh);
			Mark = (NguoiChoi == 1) ? 'X' : 'O';

			if (Danh == 1 && square[1] == '1')
				square[1] = Mark;
			else if (Danh == 2 && square[2] == '2')
				square[2] = Mark;
			else if (Danh == 3 && square[3] == '3')
				square[3] = Mark;
			else if (Danh == 4 && square[4] == '4')
				square[4] = Mark;
			else if (Danh == 5 && square[5] == '5')
				square[5] = Mark;
			else if (Danh == 6 && square[6] == '6')
				square[6] = Mark;
			else if (Danh == 7 && square[7] == '7')
				square[7] = Mark;
			else if (Danh == 8 && square[8] == '8')
				square[8] = Mark;
			else if (Danh == 9 && square[9] == '9')
				square[9] = Mark;
			else {
				printf_s("\t\t\t\t\tLua chon khong hop le moi ban danh lai \n");
				NguoiChoi--;
			}
			i = DieuKien();
			NguoiChoi++;
		} while (i == -1);

		BangChoi(Ten1, Ten2);

		if (i == 1)
			printf_s("\a\n\n\t\t\t\t\t Nguoi choi %d da chien thang UwU \n", --NguoiChoi);
		else printf_s("\t\t\t\t\t Van dau hoa T_T ");

	}


	//NGUOI CHOI VS AI


	else {
		printf_s("Nhap ten nguoi choi 1 :   "); fgetc(stdin);
		fgets(Ten1, sizeof(Ten1), stdin); fflush(stdin); Ten1[strlen(Ten1) - 1] = '\0';
		char Ten2[50] = "AI";
		


		do
		{
			BangChoi(Ten1, Ten2);
			NguoiChoi = (NguoiChoi % 2) ? 1 : 2;

			if (NguoiChoi == 1) {

				printf_s("\n\n\n\t\t\t Moi nguoi choi %d chon : ", NguoiChoi);
				scanf_s("%d", &Danh);
				Mark = 'X';

				if (Danh == 1 && square[1] == '1')
					square[1] = Mark;
				else if (Danh == 2 && square[2] == '2')
					square[2] = Mark;
				else if (Danh == 3 && square[3] == '3')
					square[3] = Mark;
				else if (Danh == 4 && square[4] == '4')
					square[4] = Mark;
				else if (Danh == 5 && square[5] == '5')
					square[5] = Mark;
				else if (Danh == 6 && square[6] == '6')
					square[6] = Mark;
				else if (Danh == 7 && square[7] == '7')
					square[7] = Mark;
				else if (Danh == 8 && square[8] == '8')
					square[8] = Mark;
				else if (Danh == 9 && square[9] == '9')
					square[9] = Mark;
				else {
					printf_s("\t\t\t\t\tLua chon khong hop le moi ban danh lai \n");
					NguoiChoi--;
				}
			}
			if (NguoiChoi == 2) {
				Mark2 = 'O';
				do {
					z = 0;
					SoNN = rand() % 10; 					//RAND_MAX = 32767 


					if (SoNN == 1 && square[1] == '1') { square[1] = Mark; break; }
					else if (SoNN == 2 && square[2] == '2') { square[2] = Mark2; break; }
					else if (SoNN == 3 && square[3] == '3') { square[3] = Mark2; break; }
					else if (SoNN == 4 && square[4] == '4') { square[4] = Mark2; break; }
					else if (SoNN == 5 && square[5] == '5') { square[5] = Mark2; break; }
					else if (SoNN == 6 && square[6] == '6') { square[6] = Mark2; break; }
					else if (SoNN == 7 && square[7] == '7') { square[7] = Mark2; break; }
					else if (SoNN == 8 && square[8] == '8') { square[8] = Mark2; break; }
					else if (SoNN == 9 && square[9] == '9') { square[9] = Mark2; break; }
					else { z = -1; };
				} while (z == -1);



			}
			i = DieuKien();
			NguoiChoi++;
		} while (i == -1);

		BangChoi(Ten1, Ten2);

		if (i == 1)
			printf_s("\a\n\n\t\t\t\t\t Nguoi choi %d da chien thang UwU \n", --NguoiChoi);
		else printf_s("\t\t\t\t\t Van dau hoa T_T ");
	}
}

