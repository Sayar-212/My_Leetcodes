int numTeams(int* rating, int ratingSize) {
    int res=0;
    for(short i=1,j,lCountAsc,rCountAsc,lCountDesc,rCountDesc;i<ratingSize-1;i++){
        lCountAsc=0,rCountAsc=0;
        for(j=0;j<i;j++)
            if(rating[j]<rating[i])
                lCountAsc++;
        lCountDesc=j-lCountAsc;
        for(j=i+1;j<ratingSize;j++)
            if(rating[j]>rating[i])
                rCountAsc++;
        rCountDesc=(j-i-1)-rCountAsc;
        
        res+=(rCountAsc*lCountAsc);
        res+=(rCountDesc*lCountDesc);
    }
    return res;
}