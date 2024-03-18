#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    vector<pair<int,int>> scores={{0,0}, {3,0}, {2,0}, {1,0}, {0,0}, {0,1}, {0,2}, {0,3}};
    string ctype="RTCFJMAN";
    vector<int> count(26, 0);
    
    for(int i=0;i<survey.size();i++){
        auto &[d, a] = scores[choices[i]];
        count[survey[i][0]-65]+=d;
        count[survey[i][1]-65]+=a;
    }
    string answer = "";
    for(int i=0;i<ctype.size();i+=2){
        if(count[ctype[i]-65]==count[ctype[i+1]-65]) answer+=ctype[i];
        else answer+=count[ctype[i]-65]>count[ctype[i+1]-65] ? ctype[i] : ctype[i+1];
    }
    return answer;
}