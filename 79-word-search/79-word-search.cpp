class Solution {
public:
    const int dx[4] = {0, 1, -1, 0};
    const int dy[4] = {1, 0, 0 - 1};
    int n;
    int m;

    bool isValid(int i, int j, int n, int m, vector <vector<char>> &board, int &cnt, string &word) {
        return (i >= 0 && i < n && j < m && j >= 0 && board[i][j] == word[cnt]);
    }

    bool dfs(int i, int j, vector <vector<char>> &board, int cnt, string &word) {
        if (cnt == word.length())return true;
        if (!isValid(i, j, n, m, board, cnt, word))return false;
        char temp = board[i][j];
        board[i][j] = '.';
        bool found = dfs(i + 1, j, board, cnt + 1, word) || dfs(i - 1, j, board, cnt + 1, word) ||
                     dfs(i, j + 1, board, cnt + 1, word) || dfs(i, j - 1, board, cnt + 1, word);
        board[i][j] = temp;
        return found;

    }

    bool exist(vector <vector<char>> &board, string word) {
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (word[0] == board[i][j] && dfs(i, j, board, 0, word)) {
                    return true;
                }
            }
        }
        return false;

    }
};