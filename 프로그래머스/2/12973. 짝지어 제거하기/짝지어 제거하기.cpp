#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    vector<int> stk;
    for(auto &e : s){
        stk.push_back(e);
        while(stk.size()>1 && stk[stk.size()-1]==stk[stk.size()-2]){
            stk.pop_back();
            stk.pop_back();
        }
    }
    return stk.size()==0;
}