class Solution {
public:
    set<vector<int>>res;
    void get(vector<int> ques, vector<int> ans){
        if(ques.size()==0)
        {res.insert(ans);
        return;}
        
        for(int i=0;i<ques.size();i++){
            vector<int> modifiedQues=ques;
            modifiedQues.erase(modifiedQues.begin()+i);
            ans.push_back(ques[i]);
            get(modifiedQues,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        get(nums,{});
        vector<vector<int>>fres;
        for(auto i:res)fres.push_back(i);
        return fres;
    }
};