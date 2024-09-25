typedef struct TrieNode {
    struct TrieNode* children[26];
    int count;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*) malloc(sizeof(TrieNode));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->count = 0;
    return node;
}

void insert(TrieNode* root, const char* word) {
    TrieNode* node = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (node->children[index] == NULL) {
            node->children[index] = createNode();
        }
        node = node->children[index];
        node->count++;
    }
}

int calculateScore(TrieNode* root, const char* word) {
    TrieNode* node = root;
    int score = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        node = node->children[index];
        score += node->count;
    }
    return score;
}

int* sumPrefixScores(char** words, int wordsSize, int* returnSize) {
    TrieNode* root = createNode();
    int* result = (int*) malloc(wordsSize * sizeof(int));

    // Step 1: Insert all words into the Trie
    for (int i = 0;i < wordsSize; i++) {
        insert(root, words[i]);
    }

    // Step 2: Calculate the score for each word
    for (int i = 0; i < wordsSize; i++) {
        result[i] = calculateScore(root, words[i]);
    }

    *returnSize = wordsSize;
    return result;
}