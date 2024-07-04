struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode* current = head->next; 
    struct ListNode* newHead = NULL;
    struct ListNode* newCurrent = NULL;
    int sum = 0;
    while (current != NULL) {
        if (current->val == 0) {
            if (sum != 0) {
                if (newHead == NULL) {
                    newHead = createNode(sum);
                    newCurrent = newHead;
                } else {
                    newCurrent->next = createNode(sum);
                    newCurrent = newCurrent->next;
                }
                sum = 0; 
            }
        } else {
            sum += current->val; 
        }
        current = current->next;
    }
    return newHead;
}
