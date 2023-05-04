#include <iostream>
using namespace std;

class TicTacToe {
public:

	TicTacToe() {
		player = 1;
	}

	void run() {
		printTicTacToe();
		while (winFlag != 1) {
			setChess();
			printf("\n");
			printTicTacToe();
			checkWin();
		}
	}
private:
	bool player;
	bool winFlag = false;
	int round = 0;
	char chesslist[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	void printTicTacToe() {
		printf("-- Tic Tac Toe -- CSIE@CGU\n");
		printf("Player 1 (x) - Player 2 (o)\n");
		printf("\n");
		printf("   ║   ║   \n");
		printf(" %c ║ %c ║ %c \n", chesslist[0], chesslist[1], chesslist[2]);
		printf("   ║   ║   \n");
		printf("═══╬═══╬═══\n");
		printf("   ║   ║   \n");
		printf(" %c ║ %c ║ %c \n", chesslist[3], chesslist[4], chesslist[5]);
		printf("   ║   ║   \n");
		printf("═══╬═══╬═══\n");
		printf("   ║   ║   \n");
		printf(" %c ║ %c ║ %c \n", chesslist[6], chesslist[7], chesslist[8]);
		printf("   ║   ║   \n");
		printf("\n");
	}

	void setChess() {
		int chess;
		if (player == 1)
			printf("Player 1, ");
		else
			printf("Player 2, ");
		printf("請輸入『1-9』的數字：");
		cin >> chess;
		if (chess < 1 || chess >9 || chesslist[chess-1] == 'o' || chesslist[chess-1] == 'x') {
			printf("請重新輸入下一步\n");
		}
		else {
			chesslist[chess - 1] = (player) ? 'x' : 'o';
			round++;
			player = !player;
		}
	}

	void checkWin() {
		for (int i = 0; i < 3; i++)			// 行
			if (chesslist[i] == ((!player) ? 'x' : 'o') && chesslist[i + 3] == ((!player) ? 'x' : 'o') && chesslist[i + 6] == ((!player) ? 'x' : 'o')) {
				printf("==>%s Win", (!player) ? "Player 1" : "Player 2");
				winFlag = 1;
				return;
			}
		for (int i = 0; i < 9; i = i + 3)	// 列
			if (chesslist[i] == ((!player) ? 'x' : 'o') && chesslist[i + 1] == ((!player) ? 'x' : 'o') && chesslist[i + 2] == ((!player) ? 'x' : 'o')) {
				printf("==>%s Win", (!player) ? "Player 1" : "Player 2");
				winFlag = 1;
				return;
			}
		// 斜線
		if (chesslist[0] == ((!player) ? 'x' : 'o') && chesslist[4] == ((!player) ? 'x' : 'o') && chesslist[8] == ((!player) ? 'x' : 'o')) {
			printf("==>%s Win", (!player) ? "Player 1" : "Player 2");
			winFlag = 1;
			return;
		}
		if (chesslist[2] == ((!player) ? 'x' : 'o') && chesslist[4] == ((!player) ? 'x' : 'o') && chesslist[6] == ((!player) ? 'x' : 'o')) {
			printf("==>%s Win", (!player) ? "Player 1" : "Player 2");
			winFlag = 1;
			return;
		}

		if (round > 8) {
			printf("==>Game draw");
			winFlag = 1;
			return;
		}

	}
};

int main() {
	TicTacToe game;
	game.run();
	return 0;
}
