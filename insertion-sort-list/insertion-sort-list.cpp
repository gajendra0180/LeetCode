class Solution {
public:
    ListNode *h,*t;
    void make(int val)
    {
        ListNode* temp=new ListNode(val);
        if(h==NULL)
        {
            h=t=temp;
        }
        else
        {
            t->next=temp;
            t=temp;
        }
    }
    ListNode* insertionSortList(ListNode* head) {
        vector<int> v;
        while(head!=NULL)
        {
            v.push_back(head->val);head=head->next;
        }
        int n = (v).size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (v[i] < v[j])
                {
                    int temp = v[i];
                    for (int k = i; k > j; k--)
                    {
                        v[k] = v[k - 1];
                    }
                    v[j] = temp;
                    break;
                }
            }
        }
        for(auto i:v)
        {
            make(i);
        }
        return h;
    }
};

