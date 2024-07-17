/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int in_delete(int* to_del, int to_del_size, int val) {
    for (int i = 0; i < to_del_size; i ++) {
        if (to_del[i] == val) {
            return 1;
        }
    }
    return 0;
}
void walk_tree(struct TreeNode** node, int* to_del, int to_del_size, struct TreeNode** forrest, int* returnSize) {
    if (*node == NULL)
        return;
    walk_tree(&(*node)->left, to_del, to_del_size, forrest, returnSize);
    walk_tree(&(*node)->right, to_del, to_del_size, forrest, returnSize);
    if (in_delete(to_del, to_del_size, (*node)->val)) {
        if ((*node)->left != NULL)
            forrest[(*returnSize) ++] = (*node)->left;
        if ((*node)->right != NULL)
            forrest[(*returnSize) ++] = (*node)->right;
        free(*node);
        *node = NULL;
    }
}
struct TreeNode** delNodes(struct TreeNode* root, int* to_delete, int to_deleteSize, int* returnSize){
    *returnSize = 0;
    struct TreeNode** forrest = malloc(sizeof(struct TreeNode*) * (to_deleteSize * 2 + 1));
    walk_tree(&root, to_delete, to_deleteSize, forrest, returnSize);
    if (root != NULL)
        forrest[(*returnSize) ++] = root;
    return forrest;
}