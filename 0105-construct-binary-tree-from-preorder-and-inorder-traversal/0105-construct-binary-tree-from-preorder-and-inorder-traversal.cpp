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
    int findpositon(vector<int> inorder,int element){
        for(int i = 0 ; i<inorder.size();i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;
    }
    TreeNode*solve(vector<int>inorder,vector<int> preorder,int &preOrderIndex ,int InOrderIndex, int InOrderEndingIndex,int n){
        if(preOrderIndex>=n||InOrderIndex>InOrderEndingIndex){
            return NULL;
        }
        int element=  preorder[preOrderIndex++];
        TreeNode * temp = new TreeNode(element);
        int positon =findpositon(inorder,element);

        // recursive calls
        temp->left = solve(inorder,preorder,preOrderIndex,InOrderIndex ,positon-1,n);
        temp->right=solve(inorder,preorder,preOrderIndex,positon+1,InOrderEndingIndex,n);
        return temp;


    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex=0;
        TreeNode* ans = solve(inorder,preorder,preOrderIndex,0,inorder.size()-1,preorder.size());
        return ans;
       
    }
};