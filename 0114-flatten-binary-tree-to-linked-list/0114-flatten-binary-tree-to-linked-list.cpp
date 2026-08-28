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
    void flatten(TreeNode* root) {
        TreeNode*curr=root;
        while(curr!=NULL){
            if(curr->left){
                TreeNode*prev=curr->left;
               //find right most node node of left subtree 
                while(prev->right!=NULL){
                    prev=prev->right;
                }
                //connect it to right side of the root
                prev->right=curr->right;
                //move leftsubtree to right
                curr->right=curr->left;
                //remove left pointers 
                curr->left=NULL;

            }
            curr=curr->right;
        }
        
    }
};