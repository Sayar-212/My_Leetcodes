int chalkReplacer(int* chalk, int chalkSize, int k) {
    long long totchalk = 0;
    for(int i=0;i<chalkSize;i++){
        totchalk+=chalk[i];
    }
    k%=totchalk;
    for(int i=0;i<chalkSize;i++){
        if(k<chalk[i]){
            return i;
        }
        k-=chalk[i];
    }
    return -1;
}