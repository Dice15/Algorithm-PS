#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int total=brown+yellow;
    
    vector<int> answer(2);
    for(int y=1;y<=total/2;y++){
        if(total%y) continue;
        if(2*y+2*(total/y)-4==brown){
            answer[0]=max(y, total/y);
            answer[1]=min(y, total/y);
        }
    }

    return answer;
}