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
    vector<int>v;
    void fun(TreeNode* root){
        if(root == NULL){
            return ;
        }
        v.push_back(root->val);
        if(root->left != NULL){
            fun(root->left);
        }
        if(root->right != NULL){
            fun(root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        fun(root);
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            int x = k - v[i];
            if(binary_search(v.begin(), v.end(), x) && v[i] != x){
                return 1;
            }
        }
        return 0;
    }
};