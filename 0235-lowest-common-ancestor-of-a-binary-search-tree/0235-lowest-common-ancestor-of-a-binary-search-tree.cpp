/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* a, TreeNode* b) {
     while(root!=NULL){
          if(root->val<a->val &&root->val<b->val){
            root=root->right;
          }
        else if(root->val>a->val&&root->val>b->val){
            root=root->left;
        }
        else {
            return root;
        }

     }
     return root;
    }
        
};