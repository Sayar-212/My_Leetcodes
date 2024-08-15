bool lemonadeChange(int* bills, int billsSize) {
    if(billsSize == 1){
        return true;
    }
    int f[3] = {0,0,0};
    for(int i = 0; i < billsSize; i++){
        if(bills[i] == 5){
            f[0]++;
        }
        else if(bills[i] == 10){
            if(f[0] > 0){
                f[0]--;
                f[1]++;
            }
            else{
                return false;
            }
        }
        else if(bills[i] == 20){
            if(f[0] > 0 && f[1] > 0){
                f[0]--;
                f[1]--;
                f[2]++;
            }
            else if(f[0] > 2){
                f[0] -= 3;
                f[2]++;
            }
            else{
                return false;
            }
        }
    }
    return true;
}