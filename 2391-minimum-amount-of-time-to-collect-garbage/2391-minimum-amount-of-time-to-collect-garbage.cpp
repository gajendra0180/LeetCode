class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ip=-1,ig=-1,im=-1;
        vector<map<char,int>>v;
        for(auto i:garbage){
            map<char,int> m;
            for(auto j:i){
                m[j]++;
            }
            v.push_back(m);
        }
        int mreq=0,preq=0,greq=0,m=0,p=0,g=0,index=0;
        
        int ind=0;
        for(auto i:v){
            if(i['P']!=0)
                ip=ind;
            if(i['G']!=0)
                ig=ind;
            if(i['M']!=0)
                im=ind;
            ind++;
        }
        // cout<<ip<<" "<<ig<<" "<<im<<endl;
        for(auto i:v){
            // cout<<index<<endl;
            if(index!=0 && index!=garbage.size()){
                if(index<=im)
                m+=travel[index-1];
                if(index<=ip)
                p+=travel[index-1];
                if(index<=ig)
                g+=travel[index-1];
            }
            index++;
            m+=i['M'];p+=i['P'];g+=i['G'];
              // cout<<m<<" "<<p<<" "<<g<<endl;
        }
        int res=0;
        return m+p+g;
    }
};