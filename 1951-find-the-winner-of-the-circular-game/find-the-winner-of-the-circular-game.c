int findTheWinner(int n, int k) {
    int friends[n];
    for (int i = 0; i < n; i++) {
        friends[i] = i + 1;  
    }
    int current_index = 0;  
    int remaining_friends = n;
    while (remaining_friends > 1) {
        for (int count = 1; count < k; count++) {
            current_index = (current_index + 1) % remaining_friends;
        }
        for (int i = current_index; i < remaining_friends - 1; i++) {
            friends[i] = friends[i + 1];  
        }
        remaining_friends--;
        if (current_index == remaining_friends) {
            current_index = 0;
        }
    }
    return friends[0];  
}