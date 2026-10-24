/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0 || lists == NULL)
    return NULL;

    struct ListNode* merged=lists[0];
    for(int i=1;i<listsSize;i++){
        struct ListNode* l1=merged;
        struct ListNode* l2=lists[i];

        struct ListNode dummy;
        struct ListNode* current = &dummy;

        while(l1!=NULL &&l2!=NULL){
            if(l1->val<l2->val){
                current->next=l1;
                l1=l1->next;
            }
            else{
                current->next=l2;
                l2=l2->next;
            }
            current=current->next;
        }
        if(l1!=NULL){
                current->next=l1;
                l1=l1->next;
                current=current->next;
        }
        else if (l2!=NULL){
                current->next=l2;
                l2=l2->next;
                current=current->next;
        }
        merged=dummy.next;
    }
    return merged ;
}