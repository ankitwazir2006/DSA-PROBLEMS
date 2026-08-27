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
    //it creates mapping  
    //return target node 
    TreeNode * CreateParentMapping(TreeNode*root,int start,map<TreeNode*,TreeNode*>&parentmapping){
        TreeNode*result;
        parentmapping[root]=NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode*front=q.front();
            q.pop();

            if(front->val==start){
                result=front;
            }
            if(front->left){
                parentmapping[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                parentmapping[front->right]=front;
                q.push(front->right);
            }
        }
        return result;

    }
    int burnTree(TreeNode*root,map<TreeNode*,TreeNode*>&parentmapping){
        map<TreeNode*,bool> visited;
        queue<TreeNode*>q;
        int ans=0;
        q.push(root);
        visited[root]=true;
        while(!q.empty()){
            bool flag=0;
             int size=q.size();
             for(int i = 0 ; i<size; i++){
                TreeNode*front= q.front();
                q.pop();
                if(front->left && !visited[front->left]){
                    q.push(front->left);
                    visited[front->left]=true;
                    flag=1;
                }
                if(front->right && !visited[front->right]){
                    q.push(front->right);
                    visited[front->right]=true;
                    flag=1;
                    
                }
                if(parentmapping[front ]&&!visited[parentmapping[front]]){
                    q.push(parentmapping[front]);
                    visited[parentmapping[front]]=true;
                    flag=1;
                }

             }
             if(flag){
                ans++;

             }
        }
        return ans;


    }
public:
    int amountOfTime(TreeNode* root, int start) {
        
        map<TreeNode*,TreeNode*>parentmapping;
        TreeNode*targetnode=CreateParentMapping(root,start,parentmapping);
        int ans=burnTree(targetnode,parentmapping);
        return ans;

    }
};