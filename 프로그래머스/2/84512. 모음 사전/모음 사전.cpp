#include <bits/stdc++.h>
using namespace std;

void makeDic(vector<string> &dic, string alphas, string s){
    if(s.size()==5) return;
    for(auto &c : alphas){
        dic.push_back(s+c);
        makeDic(dic, alphas, s+c);
    }
}

int solution(string word) {
    vector<string> dic;
    makeDic(dic, "AEIOU", "");
    return lower_bound(dic.begin(), dic.end(), word)-dic.begin()+1;
}