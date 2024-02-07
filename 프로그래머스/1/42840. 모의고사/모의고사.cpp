#include <bits/stdc++.h>
using namespace std;

int solved(vector<int> &answers, vector<int> predicts){
    int cnt=0;
    for(int i=0,j=0;i<answers.size();++i,j=(j+1)%(int)predicts.size()){
        cnt += answers[i]==predicts[j];
    }
    return cnt;
}

vector<int> solution(vector<int> answers) {    
    int s1=solved(answers, vector<int>{1, 2, 3, 4, 5});
    int s2=solved(answers, vector<int>{2, 1, 2, 3, 2, 4, 2, 5});
    int s3=solved(answers, vector<int>{3, 3, 1, 1, 2, 2, 4, 4, 5, 5});
    int ms=max(max(s1, s2), s3);
    
    vector<int> answer;
    for(auto &[p, s] : vector<pair<int,int>>{{1, s1}, {2, s2}, {3, s3}}){
        if(ms==s){
            answer.push_back(p);
        }
    }
    return answer;
}