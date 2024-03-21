#include <bits/stdc++.h>
using namespace std;

void makeSosu(vector<bool> &sosu){
    sosu[0]=sosu[1]=false;
    for(int i=2;i<sosu.size();i++){
        if(!sosu[i]) continue;
        for(int j=i+i;j<sosu.size();j+=i){
            sosu[j]=false;
        }
    }
}

int solution(string numbers) {
    vector<bool> sosu(10000000, true);
    makeSosu(sosu);
    
    vector<int> nums(numbers.begin(), numbers.end());
    for(auto &num : nums) num-=48;
    sort(nums.begin(), nums.end());
    
    int answer = 0;
    vector<bool> check(10000000, false);
    do{
        int temp=0;
        for(auto &num : nums){
            temp=(temp*10)+num;
            if(!check[temp] && sosu[temp]){
                check[temp]=true;
                answer++;
            }
        }   
    }while(next_permutation(nums.begin(), nums.end()));
    
    return answer;
}