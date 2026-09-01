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
 #include <climits>
class Solution {
    bool isbst(TreeNode*root,long long  min , long long max){
        if(root==NULL){
            return true;
        }
        if(root->val>min && root ->val<max){
            bool left= isbst(root->left, min , root->val);
            bool right=isbst(root->right, root->val,max);
            return left&&right;
        }
        else{
            return false;
        }
    }
public:
    bool isValidBST(TreeNode* root) {
         long long min = LLONG_MIN;
        long long max = LLONG_MAX;
       bool ans= isbst(root,min,max);
       return ans;

    }
};
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}