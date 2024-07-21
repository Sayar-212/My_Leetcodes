int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int canPlaceBalls(int* position, int size, int mid, int m) {
    int count = 1;
    int lastPosition = position[0];
    
    for (int i = 1; i < size; i++) {
        if (position[i] - lastPosition >= mid) {
            count++;
            lastPosition = position[i];
            if (count == m) {
                return 1;
            }
        }
    }
    
    return 0;
}

int maxDistance(int* position, int size, int m) {
    qsort(position, size, sizeof(int), compare);
    
    int start = 1;
    int end = (position[size - 1] - position[0]) / (m - 1);
    
    while (start <= end) {
        int mid = (end + start) / 2;
        if (canPlaceBalls(position, size, mid, m)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    return end;
}