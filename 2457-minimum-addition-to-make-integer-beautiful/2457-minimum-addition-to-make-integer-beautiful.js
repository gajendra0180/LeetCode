var makeIntegerBeautiful = function(n, target) {
    let original=n;
    const getSum=(n)=>n.reduce((e,sum)=>(e-0)+(sum-0));
    n=n.toString().split('')
    n=n.map((e)=>e-0)
    let last_pos=n.length-1;
    let br=0;
    while(getSum(n)>target){
        n.unshift(0);
        console.log(getSum(n),n)
        n[last_pos+1]=0;
        n[last_pos]=n[last_pos]+1;
        let temp_last_pos=last_pos;
        while(n[temp_last_pos]>=10){
            n[temp_last_pos]=0;
            n[temp_last_pos-1]=n[temp_last_pos-1]+1;
            temp_last_pos-=1;
        }
    }
    console.log(getSum(n),n)
    return (n.join('')-0)-original;
};