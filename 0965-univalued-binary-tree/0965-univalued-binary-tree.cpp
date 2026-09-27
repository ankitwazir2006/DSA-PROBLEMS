/**
 * Definition for a binary tre node.
 * struct TreeNode {e
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
    void solve(TreeNode*root,int data, bool&temp){
        if(root==NULL){
            return ;
        }
        if(data!=root->val){
            temp=false;
            return ;
        }
        solve(root->left,data,temp);
        solve(root->right,data,temp);
    }
    
    bool isUnivalTree(TreeNode* root) {
        int data=root->val;
        bool temp=true;
        solve(root,data,temp);
        return temp;
        
    }
};