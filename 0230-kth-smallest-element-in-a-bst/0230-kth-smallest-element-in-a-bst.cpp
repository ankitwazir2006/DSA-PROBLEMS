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
 int inorder(TreeNode*root,int & i , int k){
    if(root==NULL){
        return -1 ;
    }
    //left
    int left=inorder(root->left, i , k );
    if(left!=-1){
        return left;
    }
    //node
    i++;
    if(i==k){
        return root->val;
    }
    //right
    int right=inorder(root->right,i,k); 
    return right;


 }
public:
    int kthSmallest(TreeNode* root, int k) {
    int i = 0;
    int ans= inorder(root,i,k);
    return ans;
    }
};