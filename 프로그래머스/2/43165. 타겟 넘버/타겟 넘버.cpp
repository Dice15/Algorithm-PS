#include <bits/stdc++.h>
using namespace std;

int rec(vector<int> &nums, int curr, int sum, int target){
    if(curr==nums.size()) return sum==target;
    return rec(nums, curr+1, sum+nums[curr], target) + rec(nums, curr+1, sum-nums[curr], target);
}

int solution(vector<int> numbers, int target) {
    return rec(numbers, 0, 0, target);
}