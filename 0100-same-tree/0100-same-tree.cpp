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
  vector<int> tree1, tree2;
  void preorder(TreeNode* node, bool isTree1) {
    if (node == nullptr) {
        if(isTree1){tree1.push_back(0);}else{ tree2.push_back(0);}
      return;
    }
    if (isTree1)
      tree1.push_back(node->val);
    else {
      tree2.push_back(node->val);
    }
    preorder(node->left, isTree1);
    preorder(node->right, isTree1);
  }
  bool isSameTree(TreeNode* p, TreeNode* q) {
    preorder(p, true);
    preorder(q, false);
    int n = tree1.size();
    int m = tree2.size();
    if (n != m) return false;
    for (int i = 0; i < n; ++i) {
      if (tree1[i] != tree2[i]) return false;
    }
    return true;
  }
};