int longestIdealString(char * s, int k){
    
    int freq[26]={0};
    int i=0;
    int idx;
    int p;
    int distance;
    int max=1;
    int freq_temp=0;
    while(s[i]!=NULL)
    {
        idx = s[i]-'a';
        freq_temp=0;
        for (p=0; p < 26; p++)
        {  
            if (freq[p]!=0)
            {
                distance = abs(idx-p);
                if (distance <= k)
                {
                    if (freq_temp < freq[p])
                        freq_temp=freq[p];
                }
            }   
        }
        freq[idx]=freq_temp+1;
        i++;
    }
    for (i=0; i < 26; i++)
    {
        if (freq[i] > max)
            max=freq[i];
    }
    return max;
}