#include <bits/stdc++.h>
using namespace std;

vector<string> split(string &s, string p){
    regex re(p);
    sregex_token_iterator begin(s.begin(), s.end(), re, -1), end;
    return vector<string>(begin, end);
}

vector<int> solution(vector<string> park, vector<string> routes) {
    int h=park.size(), w=park[0].size(), x, y;
    auto moves=map<string, pair<int,int>>{{"N", {-1, 0}}, {"S", {1, 0}}, {"W",{0, -1}}, {"E", {0, 1}}};

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(park[i][j]=='S'){
                x=i;
                y=j;
            }
        }
    }
    
    for(auto &route : routes){
        auto cmd=split(route, " ");
        auto move=moves[cmd[0]];
        auto len=stoi(cmd[1]);
        
        int cnt=0;
        for(int i=1;i<=len;i++){
            int nx=x+move.first*i;
            int ny=y+move.second*i;
            if(0<=nx && nx<h && 0<=ny && ny<w && park[nx][ny]!='X') cnt++;
        }
        
        if(cnt==len){
            x+=move.first*len;
            y+=move.second*len;
        }     
    }
    
    return vector<int>{x, y};
}