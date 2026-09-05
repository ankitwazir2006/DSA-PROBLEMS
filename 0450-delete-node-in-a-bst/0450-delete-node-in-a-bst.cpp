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
    int minval(TreeNode* root) {

    if (root == NULL) {
        return -1;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    return root->val;
}
public:
    TreeNode* deleteNode(TreeNode* root, int val) {
         // Base case
    if (root == NULL) {
        return root;
    }

    // Found the node
    if (root->val == val) {

        // 0 child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child - left
        if (root->left != NULL && root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // 1 child - right
        if (root->left == NULL && root->right != NULL) {
              TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        // 2 children
        if (root->left != NULL && root->right != NULL) {

            // Find minimum value from right subtree
            int mini = minval(root->right);

            // Replace current node's value
            root->val = mini;

            // Delete duplicate node from right subtree
            root->right = deleteNode(root->right, mini);

            return root;
        }
        }
        
    // Value is smaller → go left
    else if (val < root->val) {
        root->left = deleteNode(root->left, val);
        return root;
    }

    // Value is greater → go right
    else {
        root->right = deleteNode(root->right, val);
        return root;
    }

    return root;
    }
        
};