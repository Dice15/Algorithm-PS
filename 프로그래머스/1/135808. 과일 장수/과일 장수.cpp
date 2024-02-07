#include <bits/stdc++.h>
using namespace std;

int solution(int k, int m, vector<int> score) {
    sort(score.begin(), score.end(), greater<int>());
    
    int answer=0;
    for(int i=0;i+m<=score.size();i+=m){
        int ms=1e9;
        for(int j=i;j<i+m;j++){
            ms=min(ms, score[j]);
        }
        answer+=ms*m;
    }
    
    return answer;
}