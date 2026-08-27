/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head) {
    
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode* node = &dummy;

    while (node->next != NULL && node->next->next != NULL) {

        struct ListNode* temp = node->next;

        node->next = node->next->next;
        temp->next = node->next->next;
        node->next->next = temp;

        node = node->next->next;
    }

    return dummy.next;
}