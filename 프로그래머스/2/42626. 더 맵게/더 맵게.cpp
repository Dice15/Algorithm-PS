#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int solution(vector<int> scoville, int K) {
    priority_queue<ll, vector<ll>, greater<ll>> pq(scoville.begin(), scoville.end());
    int answer=0;
    while(pq.size()>1 && pq.top()<K){    
        ll f=pq.top(); pq.pop();
        ll s=pq.top(); pq.pop();  
        pq.push(f+s*2);
        answer++;
    }
    return pq.top()<K ? -1 : answer;
}