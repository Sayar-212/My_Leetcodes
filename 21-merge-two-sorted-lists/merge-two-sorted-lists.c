

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) 
        return list2;
    else if (list2 == NULL) 
        return list1;
    if (list1 == NULL && list2 == NULL)
        return NULL;

    struct ListNode* root = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (list1->val > list2->val) {
        root->val = list2->val;
        list2 = list2->next;
    } else {
        root->val = list1->val;
        list1 = list1->next;
    }
    struct ListNode* iter = root;

    while (list1 != NULL && list2 != NULL) {
        iter->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        iter = iter->next;
        if (list1->val > list2->val) {
            iter->val = list2->val;
            list2 = list2->next;
        } else {
            iter->val = list1->val;
            list1 = list1->next;
        }
    }

    if (list1 == NULL && list2 != NULL) {
        while (list2 != NULL) {
            iter->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            iter = iter->next;
            iter->val = list2->val;
            list2 = list2->next;
        }
    } else if (list1 != NULL && list2 == NULL) {
        while (list1 != NULL) {
            iter->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            iter = iter->next;
            iter->val = list1->val;
            list1 = list1->next;
        }
    }

    iter->next = NULL;
    return root;
}
