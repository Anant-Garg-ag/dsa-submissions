class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> rmp;
            unordered_map<char, int> cmp;
            for (int j = 0; j < 9; j++) {
                char rc = board[i][j];
                if (rc > 48 && rc <= 57) {
                    rmp[rc]++;
                    if (rmp[rc] > 1) {
                        return false;
                    }
                }
                char c = board[j][i];
                if (c > 48 && c <= 57) {
                    cmp[c]++;
                    if (cmp[c] > 1) {
                        return false;
                    }
                }
            }
            unordered_set<char> seen;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    int r = (i / 3) * 3 + j;
                    int col = (i % 3) * 3 + k;
                    char c = board[r][col];
                    if (c == '.') continue;
                    if (seen.count(c)) return false;
                    seen.insert(c);
                }
            }
        }
        return true;
    }
};
