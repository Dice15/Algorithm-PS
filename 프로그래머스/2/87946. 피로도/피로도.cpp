#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    vector<int> p(dungeons.size());
    for(int i=0;i<p.size();i++) p[i]=i;
    
    int answer = -1;
    do{
        int remain=k;
        for(int i=0;i<p.size();i++){
            if(dungeons[p[i]][0]>remain) break;
            remain-=dungeons[p[i]][1];
            answer=max(answer, i+1);
        }
    }while(next_permutation(p.begin(), p.end()));
    
    return answer;
}