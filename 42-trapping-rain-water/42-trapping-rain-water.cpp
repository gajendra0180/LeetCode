class Solution {
public:
    int trap(vector<int>& height) {
        int base=0;
     int counter=1;
     int nsum=0;
     int s=0;
        while(counter<height.size())
        {
            if(height[counter]>=height[base])
            {
             s=s+height[base]*(counter-1-base)-nsum;
             nsum=0;
             base=counter;
             counter++;
             continue;
            }
            nsum+=height[counter];
            counter++;
        }
        int tempp=base;
        nsum=0;
        base=height.size()-1;
    //    cout<<base<<" "<<nsum<<endl; 
        for (int i = height.size()-2; i>=tempp; i--)
        {
            if(height[i]>=height[base])
            {
             s=s+height[base]*(base-i-1)-nsum;
             nsum=0;
             base=i;
             continue;
            }
            nsum+=height[i];
        }
        return s;
    }
};