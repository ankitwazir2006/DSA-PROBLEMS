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
    int findsum (TreeNode* root, int & count){
        if(root==NULL){
            return 0;
        }
        count++;
        int left=findsum(root->left,count);
        int right=findsum(root->right, count);
        int ans=left+right+root->val;
        return ans;
    }
    void solve(TreeNode* root,int &result){
         if(root==NULL){
            return ;
         }
         int count=0;
         int sum = findsum(root,count);
         if(sum/count==root->val){
             result++;
         }
         solve(root->left,result);
         solve(root->right,result);
         
    }
public:
    int averageOfSubtree(TreeNode* root) {
     if(root==NULL){
        return 0;
     }
     int result=0;
     solve(root,result);
     return result;
    }
};