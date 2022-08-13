var maximumBeauty = function(items, queries) {
  
    function b_s(ele,arr){
        let left=0,right=arr.length;
        while(left<right){
            let mid=Math.floor((right+left)/2);  
            if(arr[mid]==ele)
                return mid;
            if(arr[mid]<ele)
                left = mid+1;
            else
                right=mid;
        }
        if(arr[left]==ele)
            return left;
        else
            return left-1;
    }
    
    const map=new Map();
     let maxx=0;
     items.sort((a,b)=>a[0]-b[0])
    // console.log(items)
     items.map(([a,b])=>{
         if(map.get(a))
         {
             if(map.get(a)<b)
             {
                 map.set(a,b);
                 maxx=b;
             }
         }
         else
         {
            maxx=Math.max(maxx,b);
            map.set(a,maxx);        
         }
     });
    let keys=[],values=[],res=[]
    for(let [key,value] of map)
    {
        keys.push(key)
        values.push(value)
    }
    // console.log(keys,values);
    queries.map((q)=>{
        let index=b_s(q,keys)
        // console.log(index)
        if(index>=0)
            res.push(values[index])
        else
            res.push(0);
    })
    return res;
};