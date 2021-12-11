
class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
     
        map<int,TreeNode*> m;
        int current_level=0,chk=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='-')
                current_level++;
            else
            {
                string num;
                while(i<s.size()&&s[i]>='0'&&s[i]<='9')
                {
                    num.push_back(s[i]);
                    i++;
                }
                
                i--;
                
                stringstream ss;
                ss<<num;
                int n;
                ss>>n;
                
                TreeNode* temp=new TreeNode(n);
                
                m[current_level]=temp;
                
                if(current_level){
                    
                if(m[current_level-1]->left)
                    m[current_level-1]->right=temp;
                else
                    m[current_level-1]->left=temp;
                }
                current_level=0;
            }
        }
        return m[0];
    }
};