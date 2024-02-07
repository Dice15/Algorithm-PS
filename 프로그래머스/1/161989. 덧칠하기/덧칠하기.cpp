#include <bits/stdc++.h>
using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0, prev=-1e9;
    
    for(int i=0;i<section.size();i++){
        if(prev<=section[i] && section[i]<prev+m) continue;
        answer++;
        prev=section[i];
    }
    
    return answer;
}