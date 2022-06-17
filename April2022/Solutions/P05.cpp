// Solved by Mohammad Khan
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<vector<int>> shiftingSands(vector<vector<int>> board, vector<string> moves)
{
    for (int t = 0; t < moves.size(); t++) {
        if (moves[t] == "N") {
            for (int i = 1; i < 4; i++) {
                for (int q = 0; q < 4; q++) {
                    if (board[i-1][q] == 0) {
                        board[i-1][q] = board[i][q];
                        board[i][q] = 0;
                    }
                }
            }
            for (int i = 1; i < 4; i++) {
                for (int q = 0; q < 4; q++) {
                    if (board[i-1][q] == board[i][q]) {
                        board[i-1][q] = board[i][q]*2;
                        board[i][q] = 0;
                    }
                }
            }
            for (int i = 1; i < 4; i++) {
                for (int q = 0; q < 4; q++) {
                    if (board[i-1][q] == 0) {
                        board[i-1][q] = board[i][q];
                        board[i][q] = 0;
                    }
                }
            }
        } else if (moves[t] == "E") {
            for (int q = 2; q >= 0; q--) {
                for (int i = 0; i < 4; i++) {
                    if (board[i][q+1] == 0) {
                        board[i][q+1] = board[i][q];
                        board[i][q] = 0;
                    }
                }
            }
            for (int q = 2; q >= 0; q--) {
                for (int i = 0; i < 4; i++) {
                    if (board[i][q+1] == board[i][q]) {
                        board[i][q+1] = board[i][q]*2;
                        board[i][q] = 0;
                    }
                }
            }
            for (int q = 2; q >= 0; q--) {
                for (int i = 0; i < 4; i++) {
                    if (board[i][q+1] == 0) {
                        board[i][q+1] = board[i][q];
                        board[i][q] = 0;
                    }
                }
            }
        } else if (moves[t] == "S") {
            for (int i = 2; i >= 0; i--) {
                for (int q = 0; q < 4; q++) {
                    if (board[i+1][q] == 0) {
                        board[i+1][q] = board[i][q];
                        board[i][q] = 0;
                    }
                }
            }
            for (int i = 2; i >= 0; i--) {
                for (int q = 0; q < 4; q++) {
                    if (board[i+1][q] == board[i][q]) {
                        board[i+1][q] = board[i][q]*2;
                        board[i][q] = 0;
                    }
                }
            }
            for (int i = 2; i >= 0; i--) {
                for (int q = 0; q < 4; q++) {
                    if (board[i+1][q] == 0) {
                        board[i+1][q] = board[i][q];
                        board[i][q] = 0;
                    }
                }
            }
        } else {
            for (int q = 1; q < 4; q++) {
                for (int i = 0; i < 4; i++) {
                    if (board[i][q-1] == 0) {
                        board[i][q-1] = board[i][q];
                        board[i][q] = 0;
                    }
                }
            }
            for (int q = 1; q < 4; q++) {
                for (int i = 0; i < 4; i++) {
                    if (board[i][q-1] == board[i][q]) {
                        board[i][q-1] = board[i][q]*2;
                        board[i][q] = 0;
                    }
                }
            }
            for (int q = 1; q < 4; q++) {
                for (int i = 0; i < 4; i++) {
                    if (board[i][q-1] == 0) {
                        board[i][q-1] = board[i][q];
                        board[i][q] = 0;
                    }
                }
            }
        }
    }

    return board;
}

// Do not modify below this line
vector<string> tokenize(string s)
{
    vector<string> tokens;
    stringstream ss(s);
    string word;

    while (ss >> word)
        tokens.push_back(word);

    return tokens;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    int t;

    getline(cin, s);
    t = stoi(s);

    for (int i = 0; i < t; i++)
    {
        vector<vector<int>> board;

        for (int j = 0; j < 4; j++)
        {
            vector<int> vector_row;
            getline(cin, s);
            vector<string> vector_row_str = tokenize(s);
            for (int k = 0; k < 4; k++)
                vector_row.push_back(stoi(vector_row_str[k]));

            board.push_back(vector_row);
        }

        vector<string> moves;
        getline(cin, s);
        moves = tokenize(s);
        vector<vector<int>> output = shiftingSands(board, moves);

        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cout << output[j][k] << " ";
            }
            cout << endl;
        }
    }
}
