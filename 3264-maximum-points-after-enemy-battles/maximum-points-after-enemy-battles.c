long long maximumPoints(int* enemyEnergies, int enemyEnergiesSize, int currentEnergy) {
    int minEnergy = enemyEnergies[0];
    for (int i = 1; i < enemyEnergiesSize; ++i) {
        if (enemyEnergies[i] < minEnergy) {
            minEnergy = enemyEnergies[i];
        }
    }
    if (currentEnergy < minEnergy) {
        return 0;
    }
    long long int maxEnergy = currentEnergy;
    for (int i = 0; i < enemyEnergiesSize; ++i) {
        maxEnergy += enemyEnergies[i];
    }
    maxEnergy -= minEnergy;
    long long int maxPoints = maxEnergy / minEnergy;
    return maxPoints;
}