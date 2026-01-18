#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void placeQueen(
        int colIdx,
        vector<string> &chess,
        vector<vector<string>> &result,
        vector<int> &rowUsed,
        vector<int> &diagDown,
        vector<int> &diagUp,
        int size
    ) {
        
        if (colIdx == size) {
            result.push_back(chess);
            return;
        }

        for (int r = 0; r < size; r++) {
            if (rowUsed[r] == 0 &&
                diagDown[r + colIdx] == 0 &&
                diagUp[size - 1 + colIdx - r] == 0) {

                chess[r][colIdx] = 'Q';
                rowUsed[r] = 1;
                diagDown[r + colIdx] = 1;
                diagUp[size - 1 + colIdx - r] = 1;

                placeQueen(colIdx + 1, chess, result,
                           rowUsed, diagDown, diagUp, size);

                chess[r][colIdx] = '.';
                rowUsed[r] = 0;
                diagDown[r + colIdx] = 0;
                diagUp[size - 1 + colIdx - r] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> chessBoard(n, string(n, '.'));

        vector<int> rowUsed(n, 0);
        vector<int> diagDown(2 * n - 1, 0);
        vector<int> diagUp(2 * n - 1, 0);

        placeQueen(0, chessBoard, result,
                   rowUsed, diagDown, diagUp, n);

        return result;
    }
};
