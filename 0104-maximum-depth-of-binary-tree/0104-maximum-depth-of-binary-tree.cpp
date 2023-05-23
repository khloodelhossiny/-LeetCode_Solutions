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
    int res;
      void pfs(TreeNode* node){
        if(node == NULL){
            return;
        }
        queue<TreeNode*>q;
        q.push(node);
        while(!q.empty()){
            int c = q.size();
                res++;

            while(c--){
                TreeNode *x = q.front();
                q.pop();
               if(x->left != NULL){
                    q.push(x->left);
                } 
                if(x->right !=NULL){
                    q.push(x->right);
                }
                
            }
        }

    }
    int maxDepth(TreeNode* root) {
        pfs(root);
        return res;
    }
};