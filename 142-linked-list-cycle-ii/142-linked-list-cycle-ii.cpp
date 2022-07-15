
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,int>m;
        
        while(head){
            if(m.find(head)!=m.end())
                return head;
            m[head]++;
            head=head->next;
        }
        return NULL;
    }
};