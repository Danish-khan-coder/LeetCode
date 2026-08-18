/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max (int i,int j){
    return (i > j) ? i:j;
}
int maxDepth(struct TreeNode* root) {
   if(root == NULL){
    return 0;
   }
   int depthleft=maxDepth(root->left);
   int depthright=maxDepth(root->right);

   return 1+max(depthleft,depthright);
    
}