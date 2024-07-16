bool findPath(struct TreeNode *root, int val, char *s, int *i) {
    if(root->val == val) return true;
    if(root->left && findPath(root->left, val, s, i))   
        s[(*i)++] = 'L';
    else if(root->right && findPath(root->right, val, s, i))  
        s[(*i)++] = 'R';
    return (*i > 0);  
}
#define RANGE   100001
char * getDirections(struct TreeNode* root, int startValue, int destValue){
    char sPath[RANGE], dPath[RANGE];
    int idx = 0, sLen, dLen;
    findPath(root, startValue, sPath, &idx);
    sLen = idx;
    idx = 0;
    findPath(root, destValue, dPath, &idx);
    dLen = idx;
    while(sLen > 0 && dLen > 0 && sPath[sLen-1] == dPath[dLen-1]) {
        sLen--; 
        dLen--;
    }
    char *res = calloc(sizeof(char), (sLen + dLen + 1));
    int resIdx = 0;
    for(int i = 0; i < sLen; i++)
        res[resIdx++] = 'U';
    for(int i = dLen - 1; i >= 0; i--)
        res[resIdx++] = dPath[i];          
    return res;
}