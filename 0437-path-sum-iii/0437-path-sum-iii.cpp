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
    void finds(TreeNode * root,int k , int & count , unordered_map<long long,int>& mp,long long sum){
        if(root==NULL){
            return ; 
        }
        sum+=root->val;
        if(sum==k){
            count++;
        }
        if(mp.find(sum-k)!=mp.end()){
            count+=mp[sum-k];
        }
        mp[sum]++;
        finds(root->left,k,count,mp,sum);
        finds(root->right,k,count,mp,sum);
        mp[sum]--;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
        long long sum  = 0;
        unordered_map<long long,int> mp;

        finds(root,targetSum , count ,mp,sum);
        return count;
    }
};