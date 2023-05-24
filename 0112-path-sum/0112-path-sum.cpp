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
    bool dfs(TreeNode* root, int sum, int targetSum){
        
        if(root == NULL){
            return 0;
        }
        if((sum + root->val) == targetSum && root->left == NULL && root->right == NULL)return 1;

       return (dfs(root->left, sum + root->val,targetSum) | dfs(root->right, sum + root->val,targetSum));       
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return 0;
        }
        return dfs(root, 0, targetSum);
    }
};