class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp=head;
        while(head!=NULL&&head->next!=NULL)
        {
            int temp=head->next->val;
            head->next->val=head->val;
            head->val=temp;
            head=head->next->next;
        }
        return temp;
    }
};