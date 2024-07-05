int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = -1;
    result[1] = -1;

    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return result;
    }
    struct ListNode* prev = head;
    struct ListNode* curr = head->next;
    struct ListNode* next = head->next->next;
    int first_critical = -1;
    int last_critical = -1;
    int min_distance = INT_MAX;
    int index = 1;
    while (next != NULL) {
        if ((curr->val > prev->val && curr->val > next->val) || (curr->val < prev->val && curr->val < next->val)) {
            if (first_critical == -1) {
                first_critical = index;
            } else {
                min_distance = (index - last_critical < min_distance) ? index - last_critical : min_distance;
            }
            last_critical = index;
        }
        prev = curr;
        curr = next;
        next = next->next;
        index++;
    }
    if (first_critical != last_critical && first_critical != -1 && last_critical != -1) {
        result[0] = min_distance;
        result[1] = last_critical - first_critical;
    }
    return result;
}
