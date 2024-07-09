struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    /*Allocate memory*/
    struct ListNode* dummyNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* lastNode = dummyNode;
    int carryBit =0;
 

    while(l1||l2||carryBit)
    {
        int sol;
        int val_l1=0;
        int val_l2=0;

        /*Update Lists and calculate solution*/
        if(l1)
        {
          val_l1 = l1->val;
          l1 = l1->next;
        }
        if(l2)
        {
          val_l2 = l2->val;
          l2 = l2->next;
        }
        sol = val_l1+val_l2+carryBit;

        if(sol>9)
        {
          sol -= 10;
          carryBit = 1;
        }
        else
        {
          carryBit=0;
        }
        /*Safe values into the list*/
        struct ListNode* currentNode = (struct ListNode*)malloc(sizeof(struct ListNode));
            
        lastNode->next = currentNode;
        currentNode->val = sol;
        currentNode->next = NULL; 
        lastNode = currentNode;    
    }

    struct ListNode* firstNode = dummyNode->next;
    free(dummyNode);
    return firstNode;
}