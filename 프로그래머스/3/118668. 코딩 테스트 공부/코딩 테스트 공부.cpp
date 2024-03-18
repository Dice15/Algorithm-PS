#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solution(int alp, int cop, vector<vector<int>> problems) {
    problems.push_back(vector<int>{0, 0, 1, 0, 1});
    problems.push_back(vector<int>{0, 0, 0, 1, 1});
  
    int obtAlp=alp, obtCop=cop;
    for(auto &problem : problems){
        obtAlp=max(obtAlp, problem[0]);
        obtCop=max(obtCop, problem[1]);
    }
    
    vector<vector<ll>> dp(obtAlp+1, vector<ll>(obtCop+1, 2e18));
    dp[alp][cop]=0;
            
    for(int a=alp;a<=obtAlp;a++){
        for(int c=cop;c<=obtCop;c++){
            for(auto &problem : problems){   
                if(a<problem[0] || c<problem[1]) continue;
                int na=min(obtAlp, a+problem[2]);
                int nc=min(obtCop, c+problem[3]);   
                dp[na][nc]=min(dp[na][nc], dp[a][c]+problem[4]);
            }
        }
    }
    
    return dp[obtAlp][obtCop];
}