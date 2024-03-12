#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));
    
    for(int r=triangle.size()-1,i=0; i<triangle.size(); i++) dp[r][i]=triangle[r][i];
    for(int r=(int)triangle.size()-2; r>=0; r--){
        for(int i=0;i<=r;i++) dp[r][i]=triangle[r][i]+max(dp[r+1][i], dp[r+1][i+1]);    
    }
    
    return dp[0][0];
}