#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int solution(string t, string p) {
    int answer=0;
    ll n=1, tn=stoll(p);
    for(int i=0;i<p.size()-1;i++) n=n*10+t[i]-48;
    for(int i=p.size()-1;i<t.size();i++){
        n%=(ll)pow(10, p.size()-1);
        n=n*10+t[i]-48;
        if(n<=tn) answer++;
    }   
    return answer;
}