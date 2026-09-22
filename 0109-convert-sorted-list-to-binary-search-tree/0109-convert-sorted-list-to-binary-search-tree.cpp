/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode * solve(vector<TreeNode*>&listintotree,int left, int right){
           if(left>right){
             return NULL;
           }
           int mid= left+(right-left)/2;
           TreeNode *root= listintotree[mid];
           root->left= solve(listintotree,left,mid-1);
           root->right= solve(listintotree,mid+1,right);
           return root;
        


    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
      if(head==NULL){
        return NULL;
      }
      vector<TreeNode*>listintotree;
      while(head!=NULL){
        TreeNode* val= new TreeNode(head->val);
        listintotree.push_back(val);
        head=head->next;
      }
       TreeNode * ans=solve(listintotree,0,listintotree.size()-1);
       return ans;
      
    }
};