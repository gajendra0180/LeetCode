class Solution {
public:
    vector<vector<int>>res;
    void get(vector<int> ques, vector<int> ans){
        
        if(ques.size()==0)
        {res.push_back(ans);
        return;}
        
        for(int i=0;i<ques.size();i++){
            vector<int> modifiedQues=ques;
            modifiedQues.erase(modifiedQues.begin()+i);
            ans.push_back(ques[i]);
            get(modifiedQues,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       get(nums,{});
        return res;
    }
};