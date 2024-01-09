/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> leaf1,leaf2;
    void dfs(TreeNode* root, bool isRoot1){
        if(root->left== nullptr && root->right == nullptr){
            if(isRoot1){
                leaf1.push_back(root->val);
            }else{
                leaf2.push_back(root->val);
            }
            return;
        }
        if(root->left!=nullptr)
        dfs(root->left,isRoot1);
        if(root->right!=nullptr)
        dfs(root->right,isRoot1);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1,1);
        dfs(root2,0);
       
        return leaf1 == leaf2;
    }
};