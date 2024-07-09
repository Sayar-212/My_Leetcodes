char * longestCommonPrefix(char ** strs, int strsSize){
    for(int i = 0; i < strlen(*strs); i++)
    {
        for(int j = 1; j < strsSize; j++)
        {
            if(*(strs[0]+i) == *(strs[j]+i))
            {
                //nothing
            }
            else
            {
                char *temp = (strs[0]+i);
                *temp = '\0';
                return *strs;
            }
        }
    }
    return *strs;
}