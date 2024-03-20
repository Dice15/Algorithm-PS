#include <bits/stdc++.h>
using namespace std;

bool cmp(const string& fst, const string& snd){
    for(int i=0,j=0,z=0;z<4;z++,i=(i+1)%(int)fst.size(),j=(j+1)%(int)snd.size()){
        if(fst[i]!=snd[j]){
            return fst[i]>snd[j];
        }
    }
    return false;
}

string solution(vector<int> numbers) {
    vector<string> nums;    
    
    for(auto &number : numbers)
        nums.push_back(to_string(number));
        
    sort(nums.begin(), nums.end(), cmp);
    
    string answer = ""; 
    for(auto &num : nums) {
        if(answer.size()==0 && num=="0") continue;
        answer+=num;
    }
    return answer.size()==0 ? "0" : answer;
}