
int getLucky(char* s, int k) {
    int num=0;
    for(register int  i=0; s[i]!='\0'; i++){
        int x=s[i]-'a'+1;
        div_t qr=div(x, 10);
        num+=qr.quot+qr.rem;
    }
    k--;
    for(int x=num; x>=10 && k>0; k--){
        div_t qr;
        for(num=0; x>0; x=qr.quot){
            qr=div(x, 10);
            num+=qr.rem;
        }
        x=num;
    }
    return num;
}