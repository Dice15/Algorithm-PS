#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    set<int> wins(win_nums.begin(), win_nums.end());
    
    int zCnt=0, cCnt=0;
    for(auto &e : lottos){
        if(e==0) zCnt++;
        else if(wins.find(e)!=wins.end()) cCnt++;
    }
    return vector<int> {cCnt+zCnt==0 ? 6 : 7-(cCnt+zCnt), cCnt==0 ? 6 : 7-cCnt};
}