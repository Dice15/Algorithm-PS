#include <bits/stdc++.h>
using namespace std;

void setSosu(vector<bool> &sosu){
    sosu.assign(50001, true);
    fill(sosu.begin(), sosu.begin()+2, false);
    
    for(int i=2;i<sosu.size();i++){
        if(!sosu[i]) continue;
        for(int j=i+i;j<sosu.size();j+=i){
            sosu[j]=false;
        }
    }
}

int sosuCnt(vector<int> &nums, vector<bool> &sosu, int idx, int sum, int cnt){
    if(cnt==3) return sosu[sum];
    if(idx==nums.size()) return 0;
    
    int result=0;
    for(int i=idx;i<nums.size();i++){
        result+=sosuCnt(nums, sosu, i+1, sum+nums[i], cnt+1);
    }
    return result;
}

int solution(vector<int> nums) {
    vector<bool> sosu;
    setSosu(sosu);
    return sosuCnt(nums, sosu, 0, 0, 0);
}