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
    TreeNode*solve(vector<int>&preoder,int mini,int maxi,int &i ){
        if(i>=preoder.size()){
            return NULL;
        }
        if(preoder[i]<mini|| preoder[i]>maxi){
            return NULL;
        }
        //if in range
        TreeNode*root=new TreeNode(preoder[i++]);
        root->left=solve(preoder,mini,root->val,i);
        root->right=solve(preoder,root->val,maxi,i);
        return root;

    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini=INT_MIN;
        int maxi=INT_MAX;
        int i =0;
        return solve(preorder,mini,maxi,i);

    }
};