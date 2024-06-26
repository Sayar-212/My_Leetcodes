struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void inorderTraversal(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left, arr, index);
    arr[(*index)++] = root->val;
    inorderTraversal(root->right, arr, index);
}
struct TreeNode* sortedArrayToBST(int* arr, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int mid = start + (end - start) / 2;
    struct TreeNode* node = newNode(arr[mid]);
    node->left = sortedArrayToBST(arr, start, mid - 1);
    node->right = sortedArrayToBST(arr, mid + 1, end);
    return node;
}
int getNodeCount(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + getNodeCount(root->left) + getNodeCount(root->right);
}
struct TreeNode* balanceBST(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    int nodeCount = getNodeCount(root);
    int* arr = (int*)malloc(nodeCount * sizeof(int));
    int index = 0;
    inorderTraversal(root, arr, &index);
    struct TreeNode* balancedRoot = sortedArrayToBST(arr, 0, nodeCount - 1);
    free(arr);
    return balancedRoot;
}
void printInorder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}