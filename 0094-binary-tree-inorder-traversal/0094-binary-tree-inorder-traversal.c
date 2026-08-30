#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void traverse(struct TreeNode* node, int* arr, int* index) {
    if (node == NULL) {
        return;
    }
    
    
    traverse(node->left, arr, index);
    
    
    arr[(*index)++] = node->val;
    
  
    traverse(node->right, arr, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
 
    int* result = (int*)malloc(100 * sizeof(int));
    if (!result) {
        *returnSize = 0;
        return NULL;
    }
    
    *returnSize = 0;
    traverse(root, result, returnSize);
    
    return result;
}