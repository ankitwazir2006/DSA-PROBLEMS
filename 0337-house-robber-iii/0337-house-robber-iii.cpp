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
    pair<int,int>solve(TreeNode*root){
            if(root==NULL){
             pair<int,int> p = make_pair(0,0); // first int is when we include the root 
                                               //second int is when we exclude the root 
             return p;
         }
         pair<int,int> left=solve(root->left);
         pair<int,int> right=solve(root->right);
         pair<int,int> res;
         
         res.first= root->val+left.second+right.second;
         res.second= max(right.first,right.second)+max(left.first,left.second);
         
         return res;
    }
public:
    int rob(TreeNode* root) {
        pair<int,int> ans=solve(root);
       return max(ans.first,ans.second);
    }
};