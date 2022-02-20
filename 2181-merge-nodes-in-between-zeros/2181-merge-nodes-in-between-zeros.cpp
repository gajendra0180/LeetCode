class Solution {
public:
    ListNode *h,*t;
    void make(int val){
        ListNode* temp=new ListNode(val);
        if(h==NULL){
            h=t=temp;
        }
        else
        {
            t->next=temp;
            t=temp;
        }
    }
    
    ListNode* mergeNodes(ListNode* head) {
        vector<int> v;
        while(head!=NULL&&head->next!=NULL){
            
            if(head->val==0){
                head=head->next;
                int s=0;
                while(head->val!=0){
                    s+=head->val;
                    head=head->next;
                }   
                v.push_back(s);
            }
        }
        for(auto i:v){
            make(i);
        }
        return h;
    }
};