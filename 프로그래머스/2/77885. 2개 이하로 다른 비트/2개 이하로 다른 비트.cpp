#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> solution(vector<ll> numbers) {
    vector<ll> answer;
    for(auto &num : numbers){
        ll i=0, j=-1;
        while(num & (ll)1<<i) j=i++;  
        num |= (ll)1<<i;
        if(j>=0) num &= ~((ll)1<<j);
        answer.push_back(num);
    }
    return answer;
}