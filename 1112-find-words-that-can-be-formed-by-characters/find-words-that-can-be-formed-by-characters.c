#include <stdio.h>
#include <string.h>

int countCharacters(char** words, int wordsSize, char* chars) {
    int cnt[26] = {0};

    // Count occurrences of each character in chars
    for (int i = 0; i < strlen(chars); ++i) {
        ++cnt[chars[i] - 'a'];
    }

    int ans = 0;

    // Iterate through each word in words
    for (int k = 0; k < wordsSize; ++k) {
        int wc[26] = {0};
        int ok = 1; // Boolean variable in C

        // Iterate through each character in the current word
        for (int i = 0; i < strlen(words[k]); ++i) {
            int j = words[k][i] - 'a';

            // Check if using one more occurrence of the character would exceed the available count
            if (++wc[j] > cnt[j]) {
                ok = 0;
                break;
            }
        }

        // If the current word can be formed, add its length to the total answer
        if (ok) {
            ans += strlen(words[k]);
        }
    }

    return ans;
}

