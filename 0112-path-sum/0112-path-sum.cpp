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
    void solve(TreeNode* root , int targetsum , int sum,bool &flag){
        if(root==NULL){
           
           return ;
        }   
          sum=sum+root->val;
        if(root->left == NULL && root->right == NULL) {
            if(sum == targetsum)
            flag = true;
            return;
         }
   
        solve(root->left,targetsum,sum,flag);
        solve(root->right,targetsum,sum,flag);
    }
public:
    bool hasPathSum(TreeNode* root, int targetsum) {
       
        int sum=0;

        bool flag=false;
        solve(root,targetsum,sum,flag);
        return flag;
    }
};