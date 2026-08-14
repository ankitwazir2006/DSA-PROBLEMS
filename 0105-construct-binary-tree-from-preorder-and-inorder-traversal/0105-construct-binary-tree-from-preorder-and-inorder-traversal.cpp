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
    void createmapping(vector<int> &inorder,map<int,int>&NodeToIndex){
        for(int i = 0 ; i<inorder.size();i++){
           NodeToIndex[inorder[i]]=i;
        }
       
    }
    TreeNode*solve(vector<int>&inorder,vector<int> &preorder,int &preOrderIndex ,int InOrderIndex, int InOrderEndingIndex,int n,map<int,int>&NodeToIndex){
        if(preOrderIndex>=n||InOrderIndex>InOrderEndingIndex){
            return NULL;
        }
        int element=  preorder[preOrderIndex++];
        TreeNode * temp = new TreeNode(element);
        int positon = NodeToIndex[element];

        // recursive calls
        temp->left = solve(inorder,preorder,preOrderIndex,InOrderIndex ,positon-1,n,NodeToIndex);
        temp->right=solve(inorder,preorder,preOrderIndex,positon+1,InOrderEndingIndex,n,NodeToIndex);
        return temp;


    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex=0;
        map<int,int>NodeToIndex;

        createmapping(inorder,NodeToIndex);
        TreeNode* ans = solve(inorder,preorder,preOrderIndex,0,inorder.size()-1,preorder.size(),NodeToIndex);
        return ans;
       
    }
};