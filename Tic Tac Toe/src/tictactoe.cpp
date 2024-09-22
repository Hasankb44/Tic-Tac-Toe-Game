#include <iostream>

#define false 0
#define true 1

using namespace std;

void getBoard(char *board, size_t);
bool checkWinX(char *board, size_t);
bool checkWinO(char *board, size_t);
bool checkDraw(char *board, size_t);

int main()
{
    char board[9] = {};
    for (int i = 0; i < 9; i++) {
        board[i] = ' ';
    }
    size_t size = sizeof(board) / sizeof(char);

    char board3[3][3];
    board3[0][0] = board[0];
    board3[0][1] = board[1];
    board3[0][2] = board[2];
    board3[1][0] = board[3];
    board3[1][1] = board[4];
    board3[1][2] = board[5];
    board3[2][0] = board[6];
    board3[2][1] = board[7];
    board3[2][2] = board[8];

    /* Game Loop */
    while (true) {
        getBoard(board, size);
        int x;
        int y;

        cout << "X satirini oyna : ";
        std::cin >> x;
        cout << "X sutununu oyna : ";
        std::cin >> y;
        if (board3[x - 1][y - 1] == ' ') {
            board3[x - 1][y - 1] = 'X';
        }

        if (checkDraw(board, size)) {
            cout << "Draw!";
            break;
        }
        else if (checkWinX(board, size)) {
            cout << "X win!";
            break;
        }

        board[0] = board3[0][0];
        board[1] = board3[0][1];
        board[2] = board3[0][2];
        board[3] = board3[1][0];
        board[4] = board3[1][1];
        board[5] = board3[1][2];
        board[6] = board3[2][0];
        board[7] = board3[2][1];
        board[8] = board3[2][2];

        getBoard(board, size);

        cout << "O satirini oyna : ";
        std::cin >> x;
        cout << "O sutununu oyna : ";
        std::cin >> y;
        if (board3[y - 1][x - 1] == ' ') {
            board3[y - 1][x - 1] = 'O';
        }

        board[0] = board3[0][0];
        board[1] = board3[0][1];
        board[2] = board3[0][2];
        board[3] = board3[1][0];
        board[4] = board3[1][1];
        board[5] = board3[1][2];
        board[6] = board3[2][0];
        board[7] = board3[2][1];
        board[8] = board3[2][2];

        if (checkDraw(board, size)) {
            cout << "Draw!";
            break;
        }
        else if (checkWinO(board, size)) {
            cout << "X win!";
            break;
        }
    }

    return 0;
}

void getBoard(char *board, size_t size)
{
    string nline = "+-----+-----+-----+";

    string nline2 = "|     |     |     |";

    int j = 0;

    for (int i = 0; i < 3; i++) {
        std::cout << nline << endl;
        std::cout << nline2 << endl;
        std::cout << "|  " << board[j] << "  |  ";
        j += 1;
        std::cout << board[j] << "  |  ";
        j += 1;
        std::cout << board[j] << "  | " << endl;
        std::cout << nline2 << endl;
        if (i == 2) {
            std::cout << nline << endl;
        }
        j += 1;

    }
}

bool checkWinX(char *board, size_t size) {
    // Satırları kontrol et
    for (int i = 0; i < 3; i++) {
        if (board[i * 3] == 'X' && board[i * 3 + 1] == 'X' && board[i * 3 + 2] == 'X') {
            return true;
        }
    }

    // Sütunları kontrol et
    for (int i = 0; i < 3; i++) {
        if (board[i] == 'X' && board[i + 3] == 'X' && board[i + 6] == 'X') {
            return true;
        }
    }

    // Çaprazları kontrol et
    if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') {
        return true;
    }

    if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X') {
        return true;
    }

    return false;
}



bool checkWinO(char *board, size_t size) {
    // Satırları kontrol et
    for (int i = 0; i < 3; i++) {
        if (board[i * 3] == 'O' && board[i * 3 + 1] == 'O' && board[i * 3 + 2] == 'O') {
            return true;
        }
    }

    // Sütunları kontrol et
    for (int i = 0; i < 3; i++) {
        if (board[i] == 'O' && board[i + 3] == 'O' && board[i + 6] == 'O') {
            return true;
        }
    }

    // Çaprazları kontrol et
    if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') {
        return true;
    }

    if (board[2] == 'O' && board[4] == 'O' && board[6] == 'O') {
        return true;
    }

    return false;
}


bool checkDraw(char *board, size_t size) {
    bool empty = false;

    for (int i = 0; i < size; i++) {
        if (board[i] == ' ') {
            empty = true;
            break;
        }
    }

        if (!empty)
        {
            if (!(checkWinO(board, size)))
            {
                if (!(checkWinX(board, size)))
                {
                    return true;
                }
            }
        }
    return false;
};
