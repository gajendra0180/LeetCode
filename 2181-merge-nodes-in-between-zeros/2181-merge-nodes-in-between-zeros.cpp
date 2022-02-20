
class Solution {
public:
    ListNode *h,*t;
    ListNode* mergeNodes(ListNode* head) {
        while(head!=NULL&&head->next!=NULL){
            if(head->val==0){
                
                head=head->next;
                
                int s=0;
                
                while(head->val!=0)
                    s+=head->val,head=head->next;
                
                ListNode* temp=new ListNode(s);
                if(h==NULL)
                    h=t=temp;
                else
                    t->next=temp,t=temp;
            }
        }
        return h;
    }
};