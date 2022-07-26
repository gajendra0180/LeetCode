var search = function(nums, target) {
     let firstVal = 0;
    let lastVal = nums.length - 1;
    while (firstVal <= lastVal) {
        let mid = Math.floor((firstVal + lastVal) / 2)
        if (nums[mid] === target) {
            return mid;
        } else if (nums[mid] < target) {
            firstVal = mid+1
        } else {
            lastVal = mid -1
        }
    }
    return -1;
};

