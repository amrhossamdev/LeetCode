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
  int ans = 0;
  void dfs(TreeNode* node,int mx,int mn) {
    if (node == nullptr){
        ans = max(ans,abs(mx-mn));
        return;
    }
    mx = max(node->val, mx);
    mn = min(node->val, mn);
    dfs(node->left,mx,mn);
    dfs(node->right,mx,mn);
  }
  int maxAncestorDiff(TreeNode* root) {
    if(root == nullptr)return 0;
    dfs(root,-1e9,1e9);
    return ans;
  }
};