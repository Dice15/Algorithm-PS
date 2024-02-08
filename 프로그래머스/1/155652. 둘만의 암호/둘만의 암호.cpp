#include <bits/stdc++.h>
using namespace std;

string solution(string s, string skip, int index) {
    vector<bool> cnt(26, 1);
    for(auto &e : skip) cnt[e-97]=0;
    
    string answer = "";
    for(auto &e : s){
        int i=e-97;
        for(int c=0;c<index;i=(i+1)%26,c+=cnt[i]);
        answer+=(char)(i+97);
    }
    return answer;
}