#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;
using std::cin;

// WEEK 13
//1

void printBoardKnight(int arr[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int e1(int x, int y, int Nmove, int kn[8][8]) {

	int avMoveX[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int avMoveY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	if (Nmove == 64) return 1;

	int nextX, nextY;
	for (int i = 0; i < 8; i++) {
		nextX = x + avMoveX[i];
		nextY = y + avMoveY[i];
		if (nextX >= 0 && nextX < 8 && nextY >= 0 && nextY < 8 && kn[nextX][nextY] == -1) {
			kn[nextX][nextY] = Nmove;
			if (e1(nextX, nextY, Nmove + 1, kn) == 1) {
				return 1;
			}
			else {
				kn[nextX][nextY] = -1;
			}
		}
	}
	return 0;
}

void RUNe1() {
	int kn[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			kn[i][j] = -1;
		}
	}
	int x, y;
	cout << "Enter the X: " << endl;
	cin >> x;
	cout << "Enter the Y: " << endl;
	cin >> y;

	kn[x][y] = 0;

	if (e1(x, y, 1, kn) == 0) {
		cout << "No solution" << endl;

	}
	else {
		printBoardKnight(kn);
	}

}

//2
void printPyat(int boardP[3][3]);
bool checkDubP(int boardP[3][3], int x);
bool checkWinP(int boardP[3][3]);
void makeMove(int boardP[3][3], int num);

int boardP[3][3] = {3,7,5,
                    2,6,4,
                    1,8,0};
int mainPyatnashki() {
    srand(time(0));

    /*for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            while (true) {
                int x = rand() % 9;

                if (!checkDubP(boardP, x)) {
                    boardP[i][j] = x;
                    break;
                }
            }
        }
    }*/
    while (1) {
        printPyat(boardP);
        int num;
        cout << "Enter the number to move: ";
        cin >> num;
        makeMove(boardP, num);

        if (checkWinP(boardP)) {
            printPyat(boardP);
            cout << "WIN" << endl;
            break;
        }
    }
    return 0;
}

bool checkDubP(int boardP[3][3], int x) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (boardP[i][j] == x) {
                return true;
            }
        }
    }
    return false;
}

void makeMove(int boardP[3][3], int num) {
    int t;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (boardP[i][j] == 0) { 
                if (i > 0 && boardP[i - 1][j] == num) { 
                    t = boardP[i][j];
                    boardP[i][j] = boardP[i - 1][j];
                    boardP[i - 1][j] = t;
                    return; 
                }
                else if (j > 0 && boardP[i][j - 1] == num) { 
                    t = boardP[i][j];
                    boardP[i][j] = boardP[i][j - 1];
                    boardP[i][j - 1] = t;
                    return;
                }
                else if (i < 2 && boardP[i + 1][j] == num) { 
                    t = boardP[i][j];
                    boardP[i][j] = boardP[i + 1][j];
                    boardP[i + 1][j] = t;
                    return; 
                }
                else if (j < 2 && boardP[i][j + 1] == num) { 
                    t = boardP[i][j];
                    boardP[i][j] = boardP[i][j + 1];
                    boardP[i][j + 1] = t;
                    return;
                }
                else {
                    break;
                }
            }
        }
    }
}


bool checkWinP(int boardP[3][3]) {
    int boardW[3][3] = { 1,2,3,
                        4,5,6,
                        7,8,0 };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (boardP[i][j] != boardW[i][j]) {
                return false;
            }
        }
    }
    return true; 
}
void printPyat(int boardP[3][3]) {
    cout << "\n " << boardP[0][0] << " | " << boardP[0][1] << " | " << boardP[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << boardP[1][0] << " | " << boardP[1][1] << " | " << boardP[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << boardP[2][0] << " | " << boardP[2][1] << " | " << boardP[2][2] << "\n";
}
//3
void resboard();
void printboard();
int checkspaces();
void pmove();
int cmove();
char checkwinner();
void pwinner(char winner);
char start_player();
char startc();


char board[3][3];

char player;
char computer;

int mainXO() {

    start_player();
    startc();

    char winner = ' ';

    resboard();
    while (winner == ' ' && checkspaces() != 0) {

        printboard();
        pmove();
        winner = checkwinner();
        if (winner != ' ' || checkspaces() == 0) {
            break;
        }

        cmove();
        winner = checkwinner();
        if (winner != ' ' || checkspaces() == 0) {
            break;
        }

    }

    printboard();
    pwinner(winner);

    return 0;
}

char start_player() {
    char me;
    while (1) {
        cout << "Choose symbol(x/o): ";
        cin >> me;
        if (me == 'x' || me == 'o') {
            break;
        }
        else {
            printf("Try again. ");
        }

    }
    player = me;
    return me;

}

char startc() {
    if (player == 'x') {
        computer = 'o';
    }
    else {
        computer = 'x';
    }

    return computer;
}

void resboard() {
    int i;
    int j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printboard() {
    cout << "\n " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---";
    cout << "\n " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---";
    cout << "\n " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
}

int checkspaces() {
    int freespaces = 9;
    int i;
    int j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                freespaces--;
            }
        }
    }
    return freespaces;
}

void pmove() {
    int x;
    int y;

    while (1) {

        cout << "ROW (1-3) : ";
        cin>> x;
        x -= 1;
        cout << "Column (1-3) : ";
        cin >> y;
        y -= 1;

        if (board[x][y] != ' ' || x > 3 || x < 0 || y > 3 || y < 0) {
            printf("Invalid\n");
        }
        else
        {
            board[x][y] = player;
            break;
        }

    }

}
bool checkIf2() {
    int row;
    int colon;
    // rows
    for (row = 0; row < 3; row++) {
        int m = 0;
        if (board[row][0] == player) m++;
        if (board[row][1] == player) m++;
        if (board[row][2] == player) m++;
        if (m == 2) {
            for (int j = 0; j < 3; j++) {
                if (board[row][j] == ' ') { board[row][j] = computer; return 1; }
            }
        }
    }
    // colons
    for (colon = 0; colon < 3; colon++) {
        int m = 0;
        if (board[0][colon] == player) m++;
        if (board[1][colon] == player) m++;
        if (board[2][colon] == player) m++;
        if (m == 2) {
            for (int j = 0; j < 3; j++) {
                if (board[j][colon] == ' ') { 
                board[j][colon] = computer;
                return 1;
                }
            }
        }

    }
    // diagonals
    int m = 0;
    if (board[0][0] == player) m++;
    if (board[1][1] == player) m++;
    if (board[2][2] == player) m++;
    if (m == 2) {
        for (int j = 0; j < 3; j++) {
            if (board[j][j] == ' ') { board[j][j] = computer; return 1; }
        }
    }
    m = 0;
    if (board[0][2] == player) m++;
    if (board[1][1] == player) m++;
    if (board[2][0] == player) m++;
    if (m == 2) {
        for (int j = 0; j < 3; j++) {
            if (board[j][2-j] == ' ') { board[j][2-j] = computer; return 1; }
        }
    }
    return 0;
}

int cmove() {
    int x;
    int y;

    srand(time(NULL));

    if (checkIf2()) {
        return 0;
    }

    while (1) {

        x = rand() % 3;
        y = rand() % 3;

        if (!(board[x][y] != ' ' || x > 3 || x < 0 || y > 3 || y < 0)) {
            board[x][y] = computer;
            return 0;
        }

    }
    return -1;

}

char checkwinner() {
    int row;
    int colon;
    // rows
    for (row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][0] == board[row][2]) {
            return board[row][0];
        }

    }
    // colons
    for (colon = 0; colon < 3; colon++) {
        if (board[0][colon] == board[1][colon] && board[0][colon] == board[2][colon]) {
            return board[0][colon];
        }

    }
    // diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return board[0][0];
    }

    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return board[0][2];
    }

    return ' ';
}

void pwinner(char winner) {

    if (winner == player) {
        printf("\nYou win\n");
    }
    else if (winner == computer) {
        printf("You lose\n");
    }
    else {
        printf("Draw");
    }

}

//P2
//1
void ex1() {
    int a1[5] = { 1,2,3,4,5 };
    int a2[5];

    int* ptr1 = a1;
    int* ptr2 = a2;
    for (int i = 0; i < 5; i++) {
        *(ptr2 + i) = *(ptr1 + i);
    }
    for (int i = 0; i < 5; i++) {
        cout << a2[i] << " ";
    }
}

void ex2() {
    int a1[5] = { 1,2,3,4,5 };

    int* ptr1 = a1;
    for (int i = 4; i >= 0; i--) {
        cout << *(ptr1 + i) << " ";
    }
}

void ex3() {
    int a1[5] = { 1,2,3,4,5 };
    int a2[5];

    int* ptr1 = a1;
    int* ptr2 = &a2[5];
    for (int i = 0; i < 5; i++) {
        *(ptr2 - i - 1) = *(ptr1 + i);
    }
    for (int i = 0; i < 5; i++) {
        cout << a2[i] << " ";
    }
}
int main() {
    mainXO();
}
