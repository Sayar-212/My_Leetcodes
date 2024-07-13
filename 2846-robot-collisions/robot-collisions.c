typedef struct {
    int position;
    int health;
    char direction;
    int index;
} Robot;

int compareByPosition(const void* a, const void* b) {
    return ((Robot*)a)->position - ((Robot*)b)->position;
}

int compareByIndex(const void* a, const void* b) {
    return ((Robot*)a)->index - ((Robot*)b)->index;
}

int* survivedRobotsHealths(int* positions, int positionsSize, int* healths, int healthsSize, char* directions, int* returnSize) {
    int n = positionsSize;
    Robot* robots = (Robot*)malloc(n * sizeof(Robot));
    Robot* stack = (Robot*)malloc(n * sizeof(Robot));
    int stackSize = 0;

    for (int i = 0; i < n; ++i) {
        robots[i].position = positions[i];
        robots[i].health = healths[i];
        robots[i].direction = directions[i];
        robots[i].index = i;
    }

    qsort(robots, n, sizeof(Robot), compareByPosition);

    for (int i = 0; i < n; ++i) {
        Robot robot = robots[i];
        if (robot.direction == 'R' || stackSize == 0 || stack[stackSize - 1].direction == 'L') {
            stack[stackSize++] = robot;
            continue;
        }

        if (robot.direction == 'L') {
            int add = 1;
            while (stackSize > 0 && stack[stackSize - 1].direction == 'R' && add) {
                int last_health = stack[stackSize - 1].health;
                if (robot.health > last_health) {
                    stackSize--;
                    robot.health -= 1;
                } else if (robot.health < last_health) {
                    stack[stackSize - 1].health -= 1;
                    add = 0;
                } else {
                    stackSize--;
                    add = 0;
                }
            }

            if (add) {
                stack[stackSize++] = robot;
            }
        }
    }

    qsort(stack, stackSize, sizeof(Robot), compareByIndex);

    int* result = (int*)malloc(stackSize * sizeof(int));
    *returnSize = stackSize;
    for (int i = 0; i < stackSize; ++i) {
        result[i] = stack[i].health;
    }

    free(robots);
    free(stack);

    return result;
}