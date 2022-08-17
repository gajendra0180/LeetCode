var maxArea = function(height) {
    let start=0,end=height.length-1,waterAmount=(end-start)*Math.min(height[end],height[start]);
    while(start<end){
        waterAmount=Math.max(waterAmount,(end-start)*Math.min(height[end],height[start]));
        if(height[start]<height[end])
            start++;
        else
            end--;
    }
    return waterAmount;
};