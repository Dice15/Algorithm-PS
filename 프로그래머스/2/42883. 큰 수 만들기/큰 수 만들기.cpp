#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    for(auto &e : number){
        while(k && !answer.empty() && answer.back()<e){
            k--;
            answer.pop_back();
        }
        answer.push_back(e);
    }
    while(k) {
        k--;
        answer.pop_back();
    }
    return answer;
}