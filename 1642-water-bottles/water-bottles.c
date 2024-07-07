int numWaterBottles(int numBottles, int numExchange) {
    int totalDrank = numBottles;
    while (numBottles >= numExchange) {
        int x = numBottles / numExchange;
        int y = numBottles % numExchange;
        totalDrank += x;
        numBottles = x+y;
    }
    return totalDrank;
}