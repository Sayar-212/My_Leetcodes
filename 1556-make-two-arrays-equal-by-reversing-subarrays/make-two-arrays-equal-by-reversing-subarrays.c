
bool canBeEqual(int* targetArray, int targetArraySize, int* currentArray, int currentArraySize) {
    if (targetArraySize != currentArraySize) {
        return false;
    }
    int count[1001] = {0};
    for (int i = 0; i < targetArraySize; i++) {
        count[targetArray[i]]++;
        count[currentArray[i]]--;
    }
    for (int i = 0; i < 1001; i++) {
        if (count[i] != 0) {
            return false;
        }
    }
    return true;
}