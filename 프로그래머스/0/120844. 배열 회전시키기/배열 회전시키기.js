function solution(nums, dir) {  
    return (dir==="right" ? nums.unshift(nums.pop()) : nums.push(nums.shift())) && nums;
    
}