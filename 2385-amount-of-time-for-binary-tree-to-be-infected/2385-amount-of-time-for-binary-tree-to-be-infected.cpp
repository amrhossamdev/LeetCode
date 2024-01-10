/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  TreeNode *target;

  int amountOfTime(TreeNode *root, int start) {
    queue<TreeNode *> q;
    map<TreeNode *, TreeNode *> par;
    map<TreeNode *, bool> vis;
    q.push(root);
    int levels = 0;

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      if (cur->left != nullptr) {
        q.push(cur->left);
        par[cur->left] = cur;
      }
      if (cur->right != nullptr) {
        q.push(cur->right);
        par[cur->right] = cur;
      }
      if (cur->val == start) target = cur;
    }

    q.push(target);
    vis[target] = 1;
    while (!q.empty()) {
      bool flag = 0;
      int sz = q.size();
      while (sz--) {
        TreeNode *cur = q.front();
        q.pop();
        if (cur->right != nullptr && !vis[cur->right]) {
          q.push(cur->right);
          vis[cur->right] = 1;
          flag = 1;
        }

        if (cur->left != nullptr && !vis[cur->left]) {
          q.push(cur->left);
          vis[cur->left] = 1;
          flag = 1;
        }

        if (par[cur] != nullptr && !vis[par[cur]]) {
          q.push(par[cur]);
          vis[par[cur]] = 1;
          flag = 1;
        }
      }
      levels += flag;
    }
    return levels;
  }
};