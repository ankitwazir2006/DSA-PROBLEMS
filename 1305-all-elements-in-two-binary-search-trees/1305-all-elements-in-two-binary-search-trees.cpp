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
    vector<int>mergearray(vector<int>&arr1,vector<int>&arr2){
        vector<int>ans;
        int j=0,i=0;
        while(i<arr1.size()&&j<arr2.size()){
            if(arr1[i]<=arr2[j]){
                ans.push_back(arr1[i++]);
            }
            else{
                ans.push_back(arr2[j++]);
            }
        }
        while(i<arr1.size()){
            ans.push_back(arr1[i++]);
        }
        while(j<arr2.size()){
            ans.push_back(arr2[j++]);
        }
        return ans;
    }
       
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        //STEP1:  store inorder of two bst
        vector<int>inorder1;
        vector<int>inorder2;
        
        inorder(root1,inorder1);
        inorder(root2,inorder2);
        vector<int> meregedarray=mergearray(inorder1,inorder2);

        return meregedarray;
    }
};