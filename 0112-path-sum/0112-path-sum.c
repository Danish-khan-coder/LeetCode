/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
    
    // Empty tree
    if (root == NULL) {
        return false;
    }

    // Leaf node
    if (root->left == NULL && root->right == NULL) {
        return root->val == targetSum;
    }

    // Check left or right subtree
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}