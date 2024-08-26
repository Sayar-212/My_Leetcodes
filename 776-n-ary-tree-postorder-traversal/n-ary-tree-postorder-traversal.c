//C Code
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void postOrder(struct Node* root, int* arr, int* returnSize){
    if(!root)
        return;
    for(int i = 0; i < root->numChildren; i++)
        postOrder(root->children[i], arr, returnSize);

    arr[(*returnSize)++] = root->val;
}

int* postorder(struct Node* root, int* returnSize) {
    int* arr = (int*)calloc(sizeof(int), 10001);
    *returnSize = 0;
    
    if(!root)
        return arr;
    
    postOrder(root, arr, returnSize);
    return arr;
}