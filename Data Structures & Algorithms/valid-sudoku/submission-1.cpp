// class Solution {
//    public:
//     bool rowCheck(int row, vector<vector<char>>& board) {
//         unordered_map<char, int> mp;
//         for (int j = 0; j < 9; j++) {
//             char c = board[row][j];
//             if (c == '.') continue;
//             mp[board[row][j]]++;
//             if (mp[board[row][j]] > 1) return false;
//         }

//         return true;
//     }

//     bool colCheck(int col, vector<vector<char>>& board) {
//         unordered_map<char, int> mp;
//         for (int i = 0; i < 9; i++) {
//             char c = board[i][col];
//             if (c == '.') continue;
//             mp[board[i][col]]++;
//             if (mp[board[i][col]] > 1) return false;
//         }

//         return true;
//     }

//     bool subBoxCheck(int row, int col, vector<vector<char>>& board) {
//         int strow = (row / 3) * 3;
//         int stcol = (col / 3) * 3;
//         unordered_map<char, int> mp;

//         for (int i = strow; i < strow + 3; i++) {
//             for (int j = stcol; j < stcol + 3; j++) {
//                 char c = board[i][j];
//                 if (c == '.') continue;
//                 mp[board[i][j]]++;
//                 if (mp[board[i][j]] > 1) return false;
//             }
//         }
//         return true;
//     }

//     bool isValidSudoku(vector<vector<char>>& board) {
//         for (int i = 0; i < 9; i++) {
//             for (int j = 0; j < 9; j++) {
//                 bool rc = rowCheck(i, board);
//                 bool cc = colCheck(j, board);
//                 bool sbc = subBoxCheck(i, j, board);

//                 if (rc == false || cc == false || sbc == false) return false;
//             }
//         }

//         return true;
//     }
// };


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows
        for (int i = 0; i < 9; i++) {
            unordered_set<char> seen;
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;
                if (seen.count(c)) return false;
                seen.insert(c);
            }
        }

        // check columns
        for (int j = 0; j < 9; j++) {
            unordered_set<char> seen;
            for (int i = 0; i < 9; i++) {
                char c = board[i][j];
                if (c == '.') continue;
                if (seen.count(c)) return false;
                seen.insert(c);
            }
        }

        // check 3x3 sub-boxes
        for (int boxRow = 0; boxRow < 3; boxRow++) {
            for (int boxCol = 0; boxCol < 3; boxCol++) {
                unordered_set<char> seen;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[boxRow*3 + i][boxCol*3 + j];
                        if (c == '.') continue;
                        if (seen.count(c)) return false;
                        seen.insert(c);
                    }
                }
            }
        }

        return true;
    }
};

