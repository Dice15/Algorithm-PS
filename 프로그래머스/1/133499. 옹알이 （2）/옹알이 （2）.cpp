#include <bits/stdc++.h>
using namespace std;

void setBabblings(vector<string> &speaks, unordered_set<string> &babblings, int prev, string babbling){
    if(babbling.size()<30) babblings.insert(babbling);
    else return;
    for(int i=0;i<4;i++){
        if(i==prev) continue;
        setBabblings(speaks, babblings, i, babbling+speaks[i]);
    }
}

int solution(vector<string> babbling) {
    vector<string> speaks={"aya", "ye", "woo", "ma"};
    unordered_set<string> babblings; 
    setBabblings(speaks, babblings, -1, "");
    
    int answer = 0;
    for(auto &e :babbling){
        if(babblings.find(e)!=babblings.end()) answer++;
    }  
    return answer;
}