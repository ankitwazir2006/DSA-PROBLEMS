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
    void inorder(TreeNode*root,vector<int>&inorder1){
        if(root==NULL){
            return ;
        }
        inorder(root->left,inorder1);
        inorder1.push_back(root->val);
        inorder(root->right,inorder1);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        //STEP1:  store inorder of two bst
        vector<int>inorder1;
        
        inorder(root1,inorder1);
        inorder(root2,inorder1);
        
        
        sort(inorder1.begin(),inorder1.end());
        return inorder1;
    }
};