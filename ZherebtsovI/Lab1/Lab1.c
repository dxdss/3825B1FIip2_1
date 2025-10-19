#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void clearInput() {
	char ch = '\0';
	while ((ch = getchar()) != '\n' && ch != EOF);
}

char isKingCanMove(char pos1[3], char pos2[3]) {
	return abs(pos2[0] - pos1[0]) <= 1 && abs(pos2[1] - pos1[1]) <= 1;
}

char isRookCanMove(char pos1[3], char pos2[3]) {
	return pos2[0] - pos1[0] != 0 ^ pos2[1] - pos1[1] != 0;
}

char isBishopCanMove(char pos1[3], char pos2[3]) {
	return abs(pos2[0] - pos1[0]) == abs(pos2[1] - pos1[1]);
}

char isKnightCanMove(char pos1[3], char pos2[3]) {
	return abs(pos2[0] - pos1[0]) == 2 && abs(pos2[1] - pos1[1]) == 1 || abs(pos2[0] - pos1[0]) == 1 && abs(pos2[1] - pos1[1]) == 2;
}

char isQueenCanMove(char pos1[3], char pos2[3]) {
	return isBishopCanMove(pos1, pos2) || isRookCanMove(pos1, pos2);
}

void printCanMoveChess(char pos1[3], char pos2[3]) {
	printf("Can move:\n");
	if (isKingCanMove(pos1, pos2)) printf("- King\n");
	if (isQueenCanMove(pos1, pos2)) printf("- Queen\n");
	if (isRookCanMove(pos1, pos2)) printf("- Rook\n");
	if (isBishopCanMove(pos1, pos2)) printf("- Bishop\n");
	if (isKnightCanMove(pos1, pos2)) printf("- Knight");
}

void main() {
	char pos1[3] = "a1";
	char pos2[3] = "a1";
	unsigned short chess = 1;

	printf("Enter first position: ");
	while (scanf("%2s", &pos1) != 1 || 97 > pos1[0] || pos1[0] > 104 || 49 > pos1[1] || pos1[1] > 56) {
		printf("Encorrect enter\n");
		clearInput();
		printf("Enter first position: ");
	}

	clearInput(); //protect from enter like this:<correct_data><some_trash>

	printf("Enter second position: ");
	while (scanf("%2s", &pos2) != 1 || 97 > pos2[0] || pos2[0] > 104 || 49 > pos2[1] || pos2[1] > 56 || pos1[0] == pos2[0] && pos1[1] == pos2[1]) {
		printf("Encorrect enter\n");
		clearInput();
		printf("Enter second position: ");
	}

	clearInput();

	printf("--------------------------\n");
	printf("Select chess piece:\n1. King\n2. Queen\n3. Rook\n4. Bishop\n5. Knight\n");
	printf("Enter you choose: ");
	while (scanf("%hu", &chess) != 1 || chess == 0 || chess > 5) {
		printf("Encorrect enter\n");
		clearInput();
		printf("Enter you choose: ");
	}
	clearInput();
	printf("--------------------------\n");

	switch (chess) {
		case 1:
			if (isKingCanMove(pos1, pos2)) {
				printf("King can move");
			}
			else {
				printf("King can't move\n");
				printCanMoveChess(pos1, pos2);
			}
			break;
		case 2:
			if (isQueenCanMove(pos1, pos2)) {
				printf("Queen can move");
			}
			else {
				printf("Queen can't move\n");
				printCanMoveChess(pos1, pos2);
			}
			break;
		case 3:
			if (isRookCanMove(pos1, pos2)) {
				printf("Rook can move");
			}
			else {
				printf("Rook can't move\n");
				printCanMoveChess(pos1, pos2);
			}
			break;
		case 4:
			if (isBishopCanMove(pos1, pos2)) {
				printf("Bishop can move");
			}
			else {
				printf("Bishop can't move\n");
				printCanMoveChess(pos1, pos2);
			}
			break;
		case 5:
			if (isKnightCanMove(pos1, pos2)) {
				printf("Knight can move");
			}
			else {
				printf("Knight can't move\n");
				printCanMoveChess(pos1, pos2);
			}
			break;
	}
}