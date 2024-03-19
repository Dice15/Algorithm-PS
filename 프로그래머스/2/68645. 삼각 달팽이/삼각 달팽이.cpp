#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> tri(n+2, vector<int>(n+2, -1));
    vector<pair<int,int>> moves={{1,0}, {0,1}, {-1,-1}};
    
    for(int i=n,x=0,y=1,val=1,move=0;i>0;i--,move=(move+1)%3){
        for(int j=0;j<i;j++){
            x+=moves[move].first;
            y+=moves[move].second;
            tri[x][y]=val++;
        }
    }
    
    vector<int> answer;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            answer.push_back(tri[i][j]);
        }
    } 
    return answer;
}