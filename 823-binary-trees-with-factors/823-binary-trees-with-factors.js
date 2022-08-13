/**
 * @param {number[]} arr
 * @return {number}
 */
var numFactoredBinaryTrees = function(arr) {
    const map = new Map();
    arr.sort((a,b)=>a-b);
    let res=0;
    for(let i=0;i<arr.length;i++){
        let count=1;
        for(let j=0;j<=i-1;j++){
            if(arr[i]%arr[j]==0){
                let val=map.get(arr[j])*map.get(arr[i]/arr[j]);
                count+=val?val:0;
            }
        }
        map.set(arr[i],count);
        res+=count;
    }
    return res%(1e9+7);
};