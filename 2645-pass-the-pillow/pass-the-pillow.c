int passThePillow(int n, int time) {
    int position = 0;  
    int direction = 1; 
    for (int i = 0; i < time; ++i) {
        position += direction;
        if (position == n - 1 || position == 0) // Change direction at ends
            direction = -direction;
    }
    return position + 1; //
}