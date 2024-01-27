function solution(nums, dir) {
    return dir==="left" ? [...nums.slice(1, nums.length), nums[0]] : [nums[nums.length-1], ...nums.slice(0, nums.length-1)];
}