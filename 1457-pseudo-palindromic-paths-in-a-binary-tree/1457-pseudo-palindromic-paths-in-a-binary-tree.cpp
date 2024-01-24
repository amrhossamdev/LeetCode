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
  bool check(vector<int>& freq) {
    int odd = 0;
    int even = 0;
    for (int i = 1; i <= 9; ++i) {
      if (!freq[i]) continue;
      odd += (freq[i] & 1);
      even += !(freq[i] & 1);
    }
    return (even && (odd == 1 || !odd)) || (!even && odd == 1);
  }
  int ans = 0;
  void dfs(TreeNode* node, vector<int> &freq) {
    if (node == nullptr) {
        return;
      }
    if (node->left == nullptr && node->right == nullptr) {
      ans += check(freq);
      return;
    }
    if (node->left != nullptr) {
      freq[node->left->val]++;
      dfs(node->left, freq);
      freq[node->left->val]--;

    }
    if (node->right != nullptr) {
      freq[node->right->val]++;
      dfs(node->right, freq);
      freq[node->right->val]--;
    }
  }
  int pseudoPalindromicPaths(TreeNode* root) {
    vector<int> freq(10, 0);
    freq[root->val]++;
    dfs(root, {freq});

    return ans;
  }
};