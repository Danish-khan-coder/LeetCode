/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

struct TreeNode* createNode(int value) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));

    node->val = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct TreeNode* buildTree(int* nums, int left, int right) {

    // No elements
    if (left > right) {
        return NULL;
    }

    // Pick middle element
    int mid = left + (right - left) / 2;

    // Middle becomes root
    struct TreeNode* root = createNode(nums[mid]);

    // Build left subtree
    root->left = buildTree(nums, left, mid - 1);

    // Build right subtree
    root->right = buildTree(nums, mid + 1, right);

    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return buildTree(nums, 0, numsSize - 1);
}