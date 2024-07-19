/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int* row_minimums = (int*)malloc(rows * sizeof(int));
    int* col_maximums = (int*)malloc(cols * sizeof(int));
    for (int i = 0; i < rows; ++i) row_minimums[i] = INT_MAX;
    for (int i = 0; i < cols; ++i) col_maximums[i] = 0;
    for (int row_ind = 0; row_ind < rows; ++row_ind) {
        for (int col_ind = 0; col_ind < cols; ++col_ind) {
            int el = matrix[row_ind][col_ind];
            if (el < row_minimums[row_ind]) row_minimums[row_ind] = el;
            if (el > col_maximums[col_ind]) col_maximums[col_ind] = el;
        }
    }
    int* result = (int*)malloc(sizeof(int));
    for (int row_ind = 0; row_ind < rows; ++row_ind) {
        for (int col_ind = 0; col_ind < cols; ++col_ind) {
            int el = matrix[row_ind][col_ind];
            if (el == row_minimums[row_ind] && el == col_maximums[col_ind]) {
                result[0] = el;
                *returnSize = 1;
                free(row_minimums);
                free(col_maximums);
                return result;
            }
        }
    }
    *returnSize = 0;
    free(row_minimums);
    free(col_maximums);
    free(result);
    return NULL;
}