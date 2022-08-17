/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
        if(n==1)
            return "1";
        let prev=countAndSay(n-1);
        let i=0;
        let res='';
        while(i<prev.length){
            let j=i+1;
            while(j<prev.length&&prev[j]==prev[i])
                j++;
            res+=(j-i)+prev[i];
            i=j;
        }
    return res;
};

