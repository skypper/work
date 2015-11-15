#include <iostream>

using namespace std;

char board[9][9];
int minA = -1, minB;

char opponent(char color) {
    return color == 'W' ? 'B' : 'W';
}
void move_next(int &pos, char color) {
    if (color == 'W') {
        --pos;
    } else {
        ++pos;
    }
}

int main()
{
    //freopen("input", "r", stdin);

    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            bool blocked = false;

            if (board[i][j] != '.') {
                int k = i;
                move_next(k, board[i][j]);
                while (1 <= k && k <= 8) {
                    if (board[k][j] == opponent(board[i][j])) {
                        blocked = true;
                        break;
                    }

                    move_next(k, board[i][j]);
                }

                if (!blocked) {
                    if (board[i][j] == 'W' && minA == -1) {
                        minA = i;
                    }
                    if (board[i][j] == 'B') {
                        minB = i;
                    }
                }
            }
        }
    }
    minA = minA - 1;
    minB = 8 - minB;
    cout << (minA <= minB ? 'A' : 'B');

    return 0;
}
