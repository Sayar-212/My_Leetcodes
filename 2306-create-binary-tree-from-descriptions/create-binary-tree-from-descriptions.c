#include <stdio.h>
#include <stdlib.h>
struct TreeNode* createTreeNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct TreeNode* createBinaryTree(int** descriptions, int descriptionsSize, int* descriptionsColSize) {
    struct TreeNode* nodes[1000000] = { NULL }; 
    int isChild[1000000] = { 0 }; 
    for (int i = 0; i < descriptionsSize; i++) {
        int parentVal = descriptions[i][0];
        int childVal = descriptions[i][1];
        int isLeft = descriptions[i][2];
        if (nodes[parentVal] == NULL) {
            nodes[parentVal] = createTreeNode(parentVal);
        }
        if (nodes[childVal] == NULL) {
            nodes[childVal] = createTreeNode(childVal);
        }
        if (isLeft) {
            nodes[parentVal]->left = nodes[childVal];
        } else {
            nodes[parentVal]->right = nodes[childVal];
        }
        isChild[childVal] = 1;
    }
    for (int i = 0; i < 1000000; i++) {
        if (nodes[i] != NULL && !isChild[i]) {
            return nodes[i];
        }
    } 
    return NULL; 
}
