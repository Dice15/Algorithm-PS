#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    set<int> s;  
    for(auto &e : nums) s.insert(e); 
    return min(nums.size()/2, s.size());
}