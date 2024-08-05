char* kthDistinct(char** arr, int n, int k) {
    for(int i = 0; i < n; i++){
        bool flag = 0;
        for(int j = 0; j < n; ++j){
            if(!strcmp(arr[i], arr[j]) && i != j){
                flag = true;
                break;
            }
        }
        if(!flag){
            --k;
            if(!k)
                return arr[i];
        }
    }
    return "";
}