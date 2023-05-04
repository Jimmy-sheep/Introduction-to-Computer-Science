#include <iostream>
using namespace std;

class TicTacToe {
public:

	TicTacToe() {
		player = 1;
	}

	void run() {
		printTicTacToe(chess);
		setChess();
	}
private:
	bool player;
	char chess[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	void setChess() {
		if (player == 1) 
			printf("Player 1, ");
		else
			printf("Player 2, ");
		printf("請輸入『1-9』的數字");

	
	}

	void printTicTacToe(char chess[]) {
		printf("-- Tic Tac Toe -- CSIE@CGU\n");
		printf("Player 1 (x) - Player 2 (o)\n");
		printf("\n");
		printf("   ║   ║   \n");
		printf(" %c ║ %c ║ %c \n", chess[0], chess[1], chess[2]);
		printf("   ║   ║   \n");
		printf("═══╬═══╬═══\n");
		printf("   ║   ║   \n");
		printf(" %c ║ %c ║ %c \n", chess[3], chess[4], chess[5]);
		printf("   ║   ║   \n");
		printf("═══╬═══╬═══\n");
		printf("   ║   ║   \n");
		printf(" %c ║ %c ║ %c \n", chess[6], chess[7], chess[8]);
		printf("   ║   ║   \n");
		printf("\n");
	}
};

int main() {
	TicTacToe game;
	game.run();
	return 0;
}
