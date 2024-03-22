#include <bits/stdc++.h>
using namespace std;

int dfs(int n, int m, int r, int c, int k, int cx, int cy, string &via, vector<vector<int>> &dp, vector<tuple<char, int, int>> &moves){  
    if(dp[cx][cy]!=-1) return dp[cx][cy];
    if(k-(int)via.size() < abs(cx-r)+abs(cy-c)) return dp[cx][cy]=0;
    if(via.size()==k) return dp[cx][cy]=1;

    for(auto &[mc, mx, my] : moves){
        if(1<=cx+mx && cx+mx<=n && 1<=cy+my && cy+my<=m){
            via.push_back(mc);
            int res = dfs(n, m, r, c, k, cx+mx, cy+my, via, dp, moves);
            if(res==1) return dp[cx][cy] = 1;
            via.pop_back();
        }
    }
    return dp[cx][cy] = 0;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string via="";  
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    vector<tuple<char, int, int>> moves={{'d', 1, 0}, {'l', 0, -1}, {'r', 0, 1}, {'u', -1, 0}};
    int answer = dfs(n, m, r, c, k, x, y, via, dp, moves);
    return answer==1 ? via : "impossible";
}


// string dfs(int n, int m, int r, int c, int k, int cx, int cy, string &via, vector<vector<vector<string>>> &dp, vector<vector<int>> &cannot, vector<tuple<char, int, int>> &moves){   
//     if(k-(int)via.size() < abs(cx-r)+abs(cy-c)) return "z";
//     if(via.size()==k) {
//         if(cx==r && cy==c) {
//             if(dp[cx][cy][via.size()]=="x") return dp[cx][cy][via.size()]=via;
//             else return dp[cx][cy][via.size()];
//         }
//         else return "z";
//     }
//     if(dp[cx][cy][via.size()]!="x" && dp[cx][cy][via.size()]<=via) return "z"; 
//     dp[cx][cy][via.size()] = via;
//     string result="";
//     for(auto &[mc, mx, my] : moves){
//         if(1<=cx+mx && cx+mx<=n && 1<=cy+my && cy+my<=m){
//             via.push_back(mc);
//             string res=dfs(n, m, r, c, k, cx+mx, cy+my, via, dp, cannot, moves);
//             if(res.size()>0) {
//                 if(result=="")result=res;
//                 else result=min(result, res);
//             }
//             via.pop_back();
//         }
//     }
//     return result;
// }

// string solution(int n, int m, int x, int y, int r, int c, int k) {
//     string via="";  
//     vector<vector<vector<string>>> dp(n+1, vector<vector<string>>(m+1, vector<string>(k+1, "x")));
//     vector<vector<int>> cannot(n+1, vector<int>(m+1, -1));
//     vector<tuple<char, int, int>> moves={{'d', 1, 0}, {'l', 0, -1}, {'r', 0, 1}, {'u', -1, 0}};
//     string answer = dfs(n, m, r, c, k, x, y, via, dp, cannot, moves);
//     return answer=="z" ? "impossible" : answer;
// }