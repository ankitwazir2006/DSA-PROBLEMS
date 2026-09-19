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
    
    void inorder(TreeNode*root,vector<TreeNode*>&ans){
        if(root==NULL){
            return ;
        }

        inorder(root->left,ans);
        ans.push_back(root);
        inorder(root->right,ans);
        
    }

public:
    
    TreeNode* increasingBST(TreeNode* root) {
      vector<TreeNode*>ans;
      inorder(root,ans);
      for(int i = 0 ; i<ans.size()-1;i++){
        ans[i]->right=ans[i+1];
        ans[i]->left=NULL;
      }
      ans[ans.size()-1]->right=NULL;
      ans[ans.size()-1]->left=NULL;
      return ans[0];
    }
};