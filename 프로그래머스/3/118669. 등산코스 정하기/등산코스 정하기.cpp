#include <bits/stdc++.h>
using namespace std;

vector<int> sssp(int n, vector<vector<pair<int,int>>> &grp, vector<int> &summits, vector<bool> &isSummit){
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
    vector<vector<int>> minCost(2, vector<int>(n+1, 1000000000));

    auto enque=[&](int next, int newCost, bool visitSummit){
        if(minCost[visitSummit][next]>newCost){
            minCost[visitSummit][next]=newCost;
            pq.push({next,newCost,visitSummit});
        }
    };
    
    enque(0, 0, 0);
    while(!pq.empty()){
        auto [curr, currCost, visitSummit]=pq.top();
        pq.pop();
        
        if(minCost[visitSummit][curr]!=currCost) continue;
        
        for(auto &[next, nextCost] : grp[curr]){
            if(isSummit[next] && visitSummit) continue;
            enque(next, max(currCost, nextCost), isSummit[next] || visitSummit);
        }
    }

    vector<int> ans={1000000000, 1000000000};
    for(auto &summit : summits){
        if(ans[1] >= minCost[1][summit]){
            if(ans[1] == minCost[1][summit]) ans[0] = min(ans[0], summit);      
            else ans[0] = summit;     
            ans[1] = minCost[1][summit];
        }
    }
    return ans;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<vector<pair<int,int>>> grp(n+1); 
    vector<bool> isSummit(n+1, false);
    
    for(auto &gate : gates) {
        grp[0].push_back({gate, 0});  
    } 
    for(auto &path : paths){
        grp[path[0]].push_back({path[1], path[2]});
        grp[path[1]].push_back({path[0], path[2]});
    }
    for(auto &summit : summits){
        isSummit[summit]=true;
    }
 
    return sssp(n, grp, summits, isSummit);
}