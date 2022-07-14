class Solution {
public:
    ListNode *h,*t;
    void add(int val){
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
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        while(list1&&list2){
            if(list1->val<list2->val){
                add(list1->val);
                list1=list1->next;
            }
            else
            {
                add(list2->val);
                list2=list2->next;
            }
        }
        while(list1){add(list1->val);list1=list1->next;}
        while(list2){add(list2->val);list2=list2->next;}
        return h;
    }
};