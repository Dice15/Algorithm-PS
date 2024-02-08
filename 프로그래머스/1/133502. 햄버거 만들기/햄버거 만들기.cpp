#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> ingredient) {
    vector<int> ham={0, 1, 3, 2, 1};
    vector<int> s;
    int answer = 0;
    
    for(auto &e : ingredient){
        s.push_back(e);
        if(s.size()<4) continue;
        
        int cnt=0;
        for(int j=1;j<=4;j++){
            cnt+=ham[j]==s[s.size()-j];
        }
        if(cnt==4){
            for(int j=0;j<4;j++) s.pop_back();
            answer++;
        }
    }
    
    return answer;
}