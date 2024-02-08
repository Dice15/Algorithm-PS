#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> cnt(n+1, 1);
    for(auto &e : lost) cnt[e]--;
    for(auto &e : reserve) cnt[e]++;
    
    sort(lost.begin(), lost.end());
    for(auto &e : lost) {
        if(cnt[e]==1) continue;
        if(cnt[e-1]==2) cnt[e]=--cnt[e-1];      
        else if(cnt[e+1]==2) cnt[e]=--cnt[e+1];
    }
    
    int answer = 0;
    for(int i=1;i<=n;i++){
        if(cnt[i]) answer++;
    }  
    return answer;
}