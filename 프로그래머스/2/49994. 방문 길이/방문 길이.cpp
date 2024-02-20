#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

int solution(string dirs) {
    vector<int> check(121);
    vector<pii> moves={{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    int answer = 0, x=5, y=5, nx, ny;
    for(auto &dir : dirs) {
        int d = dir=='U' ? 0 : dir=='D' ? 1 : dir=='R' ? 2 : 3;
        nx=x + moves[d].first;
        ny=y + moves[d].second;
        if(0<=nx && nx<11 && 0<=ny && ny<11){
            if(x*11+y > nx*11+ny) d = dir=='U' ? 1 : dir=='D' ? 0 : dir=='R' ? 3 : 2;        
            if(!(check[min(x*11+y, nx*11+ny)] & 1<<d)){
                check[min(x*11+y, nx*11+ny)] |= 1<<d;
                answer++;
            }
            x=nx;
            y=ny;
        }
    }  

    return answer;
}
