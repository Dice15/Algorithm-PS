#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(s.size()), prev(26, -1);
    
    for(int i=0;i<s.size();i++){
        answer[i]=prev[s[i]-97] > -1 ? i-prev[s[i]-97] : prev[s[i]-97];
        prev[s[i]-97]=i;
    }
    
    return answer;
}