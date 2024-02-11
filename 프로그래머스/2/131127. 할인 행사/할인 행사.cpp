#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    ll w=0, answer = 0;   
    unordered_map<string, ll> p;       
    for(int i=0;i<want.size();i++) 
        w+=(ll)number[i] * p.insert({want[i], pow((ll)11, (ll)p.size())}).first->second;
        
    vector<ll> s(discount.size(), p[discount[0]]); 
    for(int i=1;i<s.size();i++)
        answer+=(s[i]=s[i-1]+p[discount[i]]-(i-10<0 ? 0 : p[discount[i-10]]))==w;

    return answer;
}