double averageWaitingTime(int** customers, int customersSize, int* customersColSize) {
    long long c = 0; 
    long long w = 0; 
    for (int i = 0; i < customersSize; i++) {
        int a = customers[i][0]; 
        int cook = customers[i][1]; 
        if (c < a) {
            c = a;
        }
        c += cook;
        w += (c - a);
    }
    return (double)w / customersSize;
}