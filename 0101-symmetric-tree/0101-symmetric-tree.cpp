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
    void solve(TreeNode* root,vector<int>&v){
        if(root==NULL){
              v.push_back(INT_MIN);
            return ;
        }
        v.push_back(root->val);
        solve(root->left,v);
       
        solve(root->right,v);
    }
    void solve1(TreeNode* root,vector<int>&v){
        if(root==NULL){
              v.push_back(INT_MIN);
            return ;
        }
        v.push_back(root->val);
        solve1(root->right,v);
        solve1(root->left,v);
       
       
    }

public:
    bool isSymmetric(TreeNode* root) {
      
        if(root->right==NULL&&root->left==NULL){
            
            return true;
        }
        if(root->right==NULL&&root->left!=NULL || root->right!=NULL&&root->left==NULL){
            return false;
        }
        vector<int>v1,v2;
        solve(root->right,v1);
        solve1(root->left,v2);
        if(v1.size()!=v2.size()){
            return false;
        }
        for(int i = 0 ; i<v1.size();i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }
        return true;

    }
};