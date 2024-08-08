
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int** spiralMatrixIII(int rows, int cols, int rStart, int cStart,
                      int* returnSize, int** returnColumnSizes) {
    // Directions array representing movements in order: right, down, left, up
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Calculate the total number of cells
    int totalCells = rows * cols;

    // Allocate memory for the result array
    int** result = (int**)malloc(totalCells * sizeof(int*));
    for (int i = 0; i < totalCells; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
    }

    // Allocate memory for returnColumnSizes and initialize it
    *returnColumnSizes = (int*)malloc(totalCells * sizeof(int));
    for (int i = 0; i < totalCells; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    // Initialize the starting position and direction
    int r = rStart, c = cStart, directionIndex = 0;
    int steps = 1;     // Number of steps to move in the current direction
    int cellCount = 0; // Number of cells visited

    // Loop until we have visited all cells
    while (cellCount < totalCells) {
        // Loop twice for each step increment
        for (int i = 0; i < 2; i++) {
            // Move in the current direction for the specified number of steps
            for (int j = 0; j < steps; j++) {
                // If the current cell is within the grid boundaries, add it to
                // the result
                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    result[cellCount][0] = r;
                    result[cellCount][1] = c;
                    cellCount++;
                }
                // Move to the next cell in the current direction
                r += directions[directionIndex][0];
                c += directions[directionIndex][1];
            }
            // Change direction (right -> down -> left -> up)
            directionIndex = (directionIndex + 1) % 4;
        }
        // Increase the number of steps after two direction changes
        steps++;
    }

    // Set the return size
    *returnSize = totalCells;
    return result;
}