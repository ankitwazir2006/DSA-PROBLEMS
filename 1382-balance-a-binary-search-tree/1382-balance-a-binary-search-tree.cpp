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
    void inorder(TreeNode*root,vector<int>&val){
        if(root==NULL){
            return ;
        }
        inorder(root->left,val);
        val.push_back(root->val);
        inorder(root->right,val);
    }
    TreeNode*solve(int s , int e , vector<int>&val){
        if(s>e){
            return NULL;
        }
        int mid =(s+e)/2;
        TreeNode* temp= new TreeNode(val[mid]);
        temp->left=solve(s,mid-1,val);
        temp->right=solve(mid+1,e,val);
        return temp;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>val;
        inorder(root,val);
    
        return solve(0,val.size()-1,val);
        
    }
};