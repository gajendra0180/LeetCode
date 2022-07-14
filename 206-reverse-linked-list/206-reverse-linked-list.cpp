class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *reversedList=reverseList(head->next);
        ListNode*temp=reversedList;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        head->next=NULL;
        return reversedList;
    }
};