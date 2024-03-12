#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> money) {
    int len=(int)money.size();
    vector<vector<int>> dp(3, vector<int>(money.size()+10, 0));      
    for(int i=len-2; i>=0; i--) dp[0][i]=max(dp[0][i+2], dp[0][i+3]) + money[i];
    for(int i=len-1; i>=1; i--) dp[1][i]=max(dp[1][i+2], dp[1][i+3]) + money[i];   
    for(int i=len-1; i>=2; i--) dp[2][i]=max(dp[2][i+2], dp[2][i+3]) + money[i];  
    return max(max(dp[0][0], dp[1][1]), dp[2][2]);
}