class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head->next==NULL)
            return NULL;
        
        ListNode *slow=head,*ultra_slow=NULL,*fast=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(ultra_slow==NULL)
                ultra_slow=head;
            else
                ultra_slow=ultra_slow->next;
        }
        ultra_slow->next=ultra_slow->next->next;
        return head;
        
    }
};