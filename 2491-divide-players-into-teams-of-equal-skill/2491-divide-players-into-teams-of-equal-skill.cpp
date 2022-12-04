class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int s=0;
        for(auto i:skill){
            s+=i;
        }
        s/=skill.size()/2;
        sort(skill.begin(),skill.end());
        long long i=0,j=skill.size()-1,ans=0;
        while(i<j){
            if(skill[i]+skill[j]!=s)
                return -1;
            else 
                ans+=skill[i]*skill[j];
            i++;j--;
        }
        return ans;
    }
};