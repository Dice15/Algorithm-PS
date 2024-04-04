#include <bits/stdc++.h>
using namespace std;

int grpSize(int prev, int curr, vector<vector<pair<int,int>>> &grp, int banEdgeId){
    int cnt=1;
    for(auto &[next, id] : grp[curr]){
        if(next==prev || id==banEdgeId) continue;
        cnt+=grpSize(curr, next, grp, banEdgeId);
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<pair<int,int>>> grp(n+1, vector<pair<int,int>>());
    
    int id=0;
    for(auto &wire : wires){
        grp[wire[0]].push_back({wire[1], id});
        grp[wire[1]].push_back({wire[0], id++});
    }
    
    int answer=2e9;
    for(int i=0;i<id;i++)
        answer=min(answer, abs((grpSize(-1, 1, grp, i)*2)-n));  
    return answer;
}