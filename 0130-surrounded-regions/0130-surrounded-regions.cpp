class Solution {
public:

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool isValid(int i, int j, int n, int m, vector <vector<char>> &board) {
        return (i >= 0 && i < n && j >= 0 && j < m && board[i][j] == 'O');
    }

    void dfs(int i, int j, int n, int m, vector <vector<char>> &board) {
        if (!isValid(i, j, n, m, board)) return;
        // mark as visited and cannot be flipped
        board[i][j] = '#';
        for (int k = 0; k < 4; ++k) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            dfs(nx, ny, n, m, board);
        }
    }

    void solve(vector <vector<char>> &board) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O')
                dfs(i, 0, n, m, board);
            if (board[i][m - 1] == 'O')
                dfs(i, m - 1, n, m, board);
        }

        for (int j = 0; j < m; ++j) {
            if (board[0][j] == 'O') {
                dfs(0, j, n, m, board);
            }
            if (board[n - 1][j] == 'O') {
                dfs(n - 1, j, n, m, board);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};