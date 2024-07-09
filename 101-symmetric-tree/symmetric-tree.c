
bool isMirror(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;

    return (root1->val == root2->val) &&
           isMirror(root1->left, root2->right) &&
           isMirror(root1->right, root2->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;
    return isMirror(root->left, root->right);
}