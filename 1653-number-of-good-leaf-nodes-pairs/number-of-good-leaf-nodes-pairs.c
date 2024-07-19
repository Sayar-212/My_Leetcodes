/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_DISTANCE 10
int countPairsHelper(struct TreeNode* root, int distance, int* count, int* depths) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) {
        depths[0] = 1;
        return 1;
    }
    int leftDepths[MAX_DISTANCE] = {0};
    int rightDepths[MAX_DISTANCE] = {0};
    int leftCount = countPairsHelper(root->left, distance, count, leftDepths);
    int rightCount = countPairsHelper(root->right, distance, count, rightDepths);
    for (int i = 0; i < MAX_DISTANCE; i++) {
        for (int j = 0; j < MAX_DISTANCE; j++) {
            if (i + j + 2 <= distance) {
                *count += leftDepths[i] * rightDepths[j];
            }
        }
    }
    for (int i = 0; i < MAX_DISTANCE - 1; i++) {
        depths[i + 1] = leftDepths[i] + rightDepths[i];
    }

    return leftCount + rightCount;
}
int countPairs(struct TreeNode* root, int distance) {
    int count = 0;
    int depths[MAX_DISTANCE] = {0};
    countPairsHelper(root, distance, &count, depths);
    return count;
}