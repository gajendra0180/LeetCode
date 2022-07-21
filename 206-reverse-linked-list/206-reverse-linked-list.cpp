class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next==NULL)
            return head;
        ListNode* prevPtr=NULL,*currPtr=head,*nextPtr=head->next;
        while(currPtr!=NULL){
            nextPtr=currPtr->next;
            currPtr->next=prevPtr;
            prevPtr=currPtr;
            currPtr=nextPtr;
        }
        return prevPtr;
    }
};