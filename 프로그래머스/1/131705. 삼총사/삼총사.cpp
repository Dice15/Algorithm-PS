#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> number) {
    vector<int> comb(number.size()-3);
    comb.resize(number.size(), 1);
    
    int answer = 0;   
    do{
        int cnt=0;
        for(int i=0;i<comb.size();i++){
            if(comb[i]) cnt+=number[i];
        }
        if(cnt==0) answer++;
    }while(next_permutation(comb.begin(), comb.end())); 
    
    return answer;
}