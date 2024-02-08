#include <bits/stdc++.h>
using namespace std;

void conv(int oCnt, vector<int> &ans){
    if(oCnt==1) return;
    int b=0, o=0;
    while(oCnt){
        if(oCnt&1) o++;
        b++;
        oCnt>>=1;
    }
    ans[0]++;
    ans[1]+=b-o;
    conv(o, ans);
}

vector<int> solution(string s) {
    vector<int> ans(2);
    
    int b=s.size(), o=0;
    for(auto &e : s) o+=e=='1';
    
    if(!(b==1 && o==1)){
        ans[0]++;
        ans[1]+=b-o;
        conv(o, ans);
    }
      
    return ans;
}