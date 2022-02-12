/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let currBest=nums[0],overallBest=nums[0]
    for(let i=1;i<nums.length;i++){
        if(nums[i]>nums[i]+currBest)
            currBest=nums[i];
        else
            currBest+=nums[i];
        overallBest=Math.max(overallBest,currBest);
    }
    return overallBest;
};