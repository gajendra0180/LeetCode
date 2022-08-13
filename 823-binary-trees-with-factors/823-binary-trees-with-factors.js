
var numFactoredBinaryTrees = function(arr) {

    let dp = new Map()
    
    function makeRoot(element,arr,set){
        let res=1;
        if(dp.get(element)){
            return dp.get(element);
        }
        for(ele of set){
            if(element%ele==0){
                let factor1=ele,factor2=element/ele;
                if(set.has(factor2))
                    res+=makeRoot(factor1,arr,set)*makeRoot(factor2,arr,set); 
            }
            if(ele==element)break;
        }
        dp.set(element,res);
        return res;
    }
    
    
    
    let res=0;
    const set= new Set()
    
    arr.sort((a,b)=>a-b);
    arr.map((e)=>set.add(e));
    arr.map((ele)=>{
        res+=makeRoot(ele,arr,set);
    })
    return res%(1e9+7);





};