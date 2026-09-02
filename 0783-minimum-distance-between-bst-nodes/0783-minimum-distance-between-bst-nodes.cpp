class Solution {
    void inorder(TreeNode* root, int& prev, int& ans) {
        if (root == NULL) {
            return;
        }

        // Left
        inorder(root->left, prev, ans);

        // Node
        if (prev != -1) {
            ans = min(ans, root->val - prev);
        }

        prev = root->val;

        // Right
        inorder(root->right, prev, ans);
    }

public:
    int minDiffInBST(TreeNode* root) {
        int prev = -1;
        int ans = INT_MAX;

        inorder(root, prev, ans);

        return ans;
    }
};