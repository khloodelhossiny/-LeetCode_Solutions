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
    bool fun(TreeNode* root, long long mx, long long mn){
        if(root == NULL){
            return 1;
        }
        if(root->val <= mn || root->val >= mx){
            return 0;
        }
        return (fun(root->left, root->val, mn) && fun(root->right, mx, root->val));
    }
    bool isValidBST(TreeNode* root) {
      return fun(root, LLONG_MAX, LLONG_MIN);
    }
    
};