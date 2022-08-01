class Solution {
 public:
  int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
  int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
  bool isValid(int i, int j, int n) {
    return (i >= 0 && i < n && j >= 0 && j < n);
  }
  bool isValidSudoku(vector<vector<char>>& board) {
    int n = board.size();
    set<char> st;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; j++) {
        if (st.find(board[i][j]) == st.end() && board[i][j] != '.') {
          st.insert(board[i][j]);
        } else if (board[i][j] != '.' && st.find(board[i][j]) != st.end()) {
          return false;
        }
      }
      st = {};
    }
    st = {};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; j++) {
        if (st.find(board[j][i]) == st.end() && board[j][i] != '.') {
          st.insert(board[j][i]);
        } else if (board[j][i] != '.' && st.find(board[j][i]) != st.end()) {
          return false;
        }
      }
      st = {};
    }
    st.clear();
    for (int i = 1; i < n; i += 3) {
      for (int j = 1; j < n; j += 3) {
        for (int k = 0; k < 8; ++k) {
          int r = i + dx[k];
          int c = j + dy[k];
          if (st.find(board[i][j]) == st.end() && board[i][j] != '.')
            st.insert(board[i][j]);
          if (isValid(r, c, n)) {
            if (board[r][c] != '.') {
              if (st.find(board[r][c]) == st.end()) {
                st.insert(board[r][c]);
              } else {
                return false;
              }
            }
          }
        }
        st = {};
      }
    }
    return true;
  }
};