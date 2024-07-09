bool isPalindrome(int x)
{
    long long int rem,rev=0,tem=x;
    if(tem<0) 
    return 0;
    while(tem!=0){
        rem = tem%10;
        rev = rev*10 + rem;
        tem = tem/10;
    }
    
    return (rev==x) ;  
} 