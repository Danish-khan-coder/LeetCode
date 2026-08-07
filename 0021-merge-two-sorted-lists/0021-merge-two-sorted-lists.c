#include <stdlib.h>


void addNode(struct ListNode *head, int value) {
    struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
    node->val = value;
    node->next = NULL;

    struct ListNode *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    // Dummy node
    struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode));
    result->next = NULL;

    while (list1 != NULL && list2 != NULL) {

        if (list1->val <= list2->val) {
            addNode(result, list1->val);
            list1 = list1->next;
        }
        else {
            addNode(result, list2->val);
            list2 = list2->next;
        }
    }

    while (list1 != NULL) {
        addNode(result, list1->val);
        list1 = list1->next;
    }

    while (list2 != NULL) {
        addNode(result, list2->val);
        list2 = list2->next;
    }

    struct ListNode *head = result->next;
    free(result);          
    return head;
}