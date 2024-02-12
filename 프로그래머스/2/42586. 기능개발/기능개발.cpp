#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> p, vector<int> s) {
    vector<int> answer(1, p.size()>0);
    for(int i=1,j=0;i<p.size();i++){
        if(ceil((100.0-p[j])/s[j])>=ceil((100.0-p[i])/s[i])) answer.back()++;
        else {
            answer.push_back(1);
            j=i;
        }
    }
    return answer;
}