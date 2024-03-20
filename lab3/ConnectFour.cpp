#include "ConnectFour.h"

ConnectFour::ConnectFour() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            m_board[i][j] = Empty;
        }
    }
    for (int i = 0; i < 7; ++i) {
        m_board_c[i] = 0;
    }
    // memset(m_board_c, 0, sizeof(m_board_c));
}

void ConnectFour::Place(int step, int column) {
    // cout << ((step % 2) == 0 ? "PlayerA" : "PlayerB")
    //      << " placed in column: " << column << endl;

    m_board[m_board_c[column]++][column] = ((step % 2) == 0 ? PlayerA : PlayerB);

    return;
}

Status ConnectFour::GetGameStatus() {
    // Return current status.

    bool checking_board[6][7] = {false};

    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (checking_board[i][j]) {
                break;
            }

            checking_board[i][j] = true;

            if (m_board[i][j] != Empty) {
                int lasting_length = 0;
                int temp_x = i;
                int temp_y = j;
                Grid player_selected = m_board[i][j];

                // check through right side

                while (temp_y < 7) {
                    lasting_length++;
                    if (player_selected != m_board[i][temp_y]) break;

                    if (lasting_length >= 4) {
                        // player_selected win;
                        if (player_selected == PlayerA) return PlayerAWin;
                        if (player_selected == PlayerB) return PlayerBWin;
                    }
                    temp_y++;
                }

                // check through upper side

                temp_x = i;
                temp_y = j;
                lasting_length = 0;
                while (temp_x < 6) {
                    lasting_length++;
                    if (player_selected != m_board[temp_x][j]) break;
                    if (lasting_length >= 4) {
                        if (player_selected == PlayerA) return PlayerAWin;
                        if (player_selected == PlayerB) return PlayerBWin;
                    }
                    temp_x++;
                }

                // check through diagnal side

                temp_x = i;
                temp_y = j;
                lasting_length = 0;
                while (temp_x < 6 && temp_y < 7) {
                    lasting_length++;
                    if (player_selected != m_board[temp_x][temp_y]) break;
                    if (lasting_length >= 4) {
                        if (player_selected == PlayerA) return PlayerAWin;
                        if (player_selected == PlayerB) return PlayerBWin;
                    }
                    temp_x++;
                    temp_y++;
                }
            }
        }
    }

    return Playing;
}

void ConnectFour::PrintBoard() {
    // Print the board.
    for (int i = 5; i >= 0; --i) {
        for (int j = 0; j < 7; ++j) {
            switch (m_board[i][j]) {
                case Empty:
                    cout << "=";
                    break;
                case PlayerA:
                    cout << "o";
                    break;
                case PlayerB:
                    cout << "x";
                    break;
            }
            // cout << (m_board[i][j] == PlayerA ? "x" : "o");
        }
        cout << endl;
    }
}

void ConnectFour::PrintWinner() {
    // Use GetGameStatus() to print the winner.
    switch (this->GetGameStatus()) {
        case PlayerAWin:
            cout << "PlayerA win!" << endl;
            break;
        case PlayerBWin:
            cout << "PlayerB win!" << endl;
            break;
        case Draw:
        case Playing:
            cout << "Draw" << endl;
            break;
    }
}