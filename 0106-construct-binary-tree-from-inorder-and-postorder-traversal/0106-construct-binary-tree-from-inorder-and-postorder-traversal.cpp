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
    void createmapping(vector<int>&inorder,map<int,int>&NodeToIndex){
        for(int i = 0  ;i < inorder.size() ; i++){
            NodeToIndex[inorder[i]]=i;
        }
    }
    TreeNode * solve( vector<int>& inorder, vector<int>& postorder, int&postorderstart, int inorderstart,int inorderend , int size , map<int,int> &NodeToIndex){
        //base case
        if(postorderstart<0 || inorderstart>inorderend ){
            return NULL;
        }
            // creating node to insert at tree
            int element = postorder[postorderstart--];
            TreeNode * temp =  new TreeNode(element);
            int position = NodeToIndex[element];

            // right call as first we go right then we go left in the tree 

            temp->right = solve(inorder,postorder, postorderstart , position+1 , inorderend , size , NodeToIndex);
            temp->left = solve(inorder,postorder, postorderstart , inorderstart , position-1 , size , NodeToIndex);
            return temp;


        
    }
   public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderindex = postorder.size()-1;
        map<int,int>NodeToIndex;
        createmapping(inorder,NodeToIndex);
        //                                       starting index , inorderstarting index  , inorderending index ,
        TreeNode * ans = solve(inorder,postorder,postorderindex, 0 , inorder.size()-1, postorder.size(),NodeToIndex);
        return ans;
    }

};