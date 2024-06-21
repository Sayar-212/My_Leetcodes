int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes) {
    int result=0, sumL=0, sumR=0, i;

    for(i=0; i<minutes; i++)
    { sumL+=customers[i]; }
    for(i=grumpySize-1; i>=minutes; i--)
    { sumR+=(grumpy[i]?0:customers[i]); }
    for(result=sumL+sumR, i=minutes; i<customersSize; i++) {
        sumL+=customers[i]-(grumpy[i-minutes]?customers[i-minutes]:0);
        sumR-=(grumpy[i]?0:customers[i]);
        result=result>=sumL+sumR?result:sumL+sumR;
    }

    return result;
}