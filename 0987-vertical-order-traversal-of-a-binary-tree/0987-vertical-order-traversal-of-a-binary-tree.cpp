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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> mp;
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue <pair<TreeNode*,pair<int,int>>> q; // ist int is horizontal distance , 2nd int is its level 
        q.push(make_pair(root, make_pair(0,0)));
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> temp=q.front();
            q.pop();
            int hd=temp.second.first;
            int level= temp.second.second;
            TreeNode*frontnode= temp.first;
            mp[hd][level].push_back(frontnode->val);

            if(frontnode->left){
                q.push(make_pair(frontnode->left,make_pair(hd-1,level+1)));
            }
            if(frontnode->right){
                q.push(make_pair(frontnode->right,make_pair(hd+1,level+1)));
            }

        }
        
        for(auto i: mp){
             vector<int> temp;
             //i==<TreeNode*,map<int,vector<int>>>
             for(auto j: i.second ){
                sort(j.second.begin(),j.second.end());
                for(int k : j.second){
                    temp.push_back(k);
                }
             }
             ans.push_back(temp);
        }
        return ans;
    }
};