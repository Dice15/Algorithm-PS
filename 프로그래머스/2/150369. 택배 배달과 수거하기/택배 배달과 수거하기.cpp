#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    ll answer = 0;
    int dIdx=n-1, pIdx=n-1;
    
    while(1){
        while(dIdx>=0 && deliveries[dIdx]==0) dIdx--;
        while(pIdx>=0 && pickups[pIdx]==0) pIdx--;
        if(dIdx<0 && pIdx<0) break;
        
        ll mIdx=max(dIdx, pIdx);
        answer+=(mIdx+1)*2;
        
        for(int i=cap;i>0 && dIdx>=0;){
            if(deliveries[dIdx]>=i) {
                deliveries[dIdx]-=i;
                i=0;
            }
            else{
                i-=deliveries[dIdx];
                deliveries[dIdx--]=0;
            }       
        }
        
        for(int i=cap;i>0 && pIdx>=0;){
            if(pickups[pIdx]>=i) {
                pickups[pIdx]-=i;
                i=0;
            }
            else{
                i-=pickups[pIdx];
                pickups[pIdx--]=0;
            }       
        }
    }
    
    return answer;
}