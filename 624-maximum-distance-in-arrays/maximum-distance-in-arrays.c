int maxDistance(int** arrays, int arraysSize, int* arraysColSize){
    int minVal = arrays[0][0];
    int maxVal = arrays[0][arraysColSize[0] - 1];
    int maxDistance = 0;

    for (int i = 1; i < arraysSize; i++) {
        int currentMin = arrays[i][0];
        int currentMax = arrays[i][arraysColSize[i] - 1];

        if (abs(currentMax - minVal) > maxDistance)
            maxDistance = abs(currentMax - minVal);
        if (abs(maxVal - currentMin) > maxDistance)
            maxDistance = abs(maxVal - currentMin);

        if (currentMin < minVal)
            minVal = currentMin;
        if (currentMax > maxVal)
            maxVal = currentMax;
    }

    return maxDistance;
}