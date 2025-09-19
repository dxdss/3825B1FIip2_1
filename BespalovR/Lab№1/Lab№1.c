//Libraries
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


void main() {


	//Input ( no checking )
	int CS;
	printf("Input starting position collum.( A = 1 , B = 2 etc. )\n");
	scanf("%d", &CS);

	int RS;
	printf("Input starting position row.\n");
	scanf("%d", &RS);

	int CE;
	printf("Input ending position collum.( A = 1 , B = 2 etc. )\n");
	scanf("%d", &CE);

	int RE;
	printf("Input ending position row.\n");
	scanf("%d", &RE);

	int Piece;
	printf("Input piece. ( Rook - 1 , Bishop - 2 , Queen - 3 , Knight - 4 , King - 5 )\n");
	scanf("%d", &Piece);


	int CD = abs(CE - CS);
	int RD = abs(RE - RS);


	//Enum for chess pieces for the sake of readability
	enum PIECE {
		Rook = 1,
		Bishop = 2,
		Queen = 3,
		Knight = 4,
		King = 5
	};


	//Starting and ending positions are the same
	if (CD == 0 && RD == 0) {
		printf("Starting and endinng positions match.\n");
	}


	//Ifs and output
	else if ((CD == 2 && RD == 1) || (CD == 1 && RD == 2)) {

		if (Piece == Knight) {
			printf("Piece can move to that space.\n");
		}

		else {
			printf("Knight can move to that space.\n");
		}
	}


	else if (CD == 0 || RD == 0 || CD == RD) {

		if (Piece == Queen) {
			printf("Piece can move to that space.\n");
		}

		else {
			printf("Queen can move to that space.\n");
		}

		if (CD <= 1 && RD <= 1) {

			if (Piece == King) {
				printf("Piece can move to that space.\n");
			}

			else {
				printf("King can move to that space.\n");
			}
		}

		if (CD == 0 || RD == 0) {

			if (Piece == Rook) {
				printf("Piece can move to that space.\n");
			}

			else {
				printf("Rook can move to that space.\n");
			}
		}

		else if (CD == RD) {

			if (Piece == Bishop) {
				printf("Piece can move to that space.\n");
			}

			else {
				printf("Bishop can move to that space.\n");
			}
		}
	}
}