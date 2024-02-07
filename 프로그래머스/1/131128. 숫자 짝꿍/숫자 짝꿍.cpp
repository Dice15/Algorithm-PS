#include <bits/stdc++.h>
using namespace std;

string solution(string X, string Y) {
    vector<pair<int, int>> cnt(10);
    
    for(auto &e : X) cnt[e-48].first++;
    for(auto &e : Y) cnt[e-48].second++;
    
    string answer = "";
    for(int i=9;i>=0;i--){
        for(int j=min(min(cnt[i].first, cnt[i].second), (i==0 && answer.size()==0) ? 1 : (int)1e9); j>0; j--){
            answer+=(char)(i+48);
        }
    }
    return answer=="" ? "-1" : answer;
}