#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solution(vector<int> queue1, vector<int> queue2) {
    vector<int> arr;
    ll q1Sum = 0, q2Sum=0;
    for(auto &e : queue1) { q1Sum+=e; arr.push_back(e); }
    for(auto &e : queue2) { q2Sum+=e; arr.push_back(e); }   
    for(auto &e : queue1) { arr.push_back(e); }
    
    if((q1Sum+q2Sum)%2) return -1;
       
    int answer=0, l=0, r=queue1.size()-1;
    ll obtSum=(q1Sum+q2Sum)/2;
    while(1){
        if(q1Sum==obtSum) break;
        else if(q1Sum>obtSum){
            if(l<r){
                q1Sum-=arr[l++];
                answer++;
            }
            else if(l==r){
                q1Sum=arr[l=++r];
                answer+=2;
            }
        }
        else if(q1Sum<obtSum){
            if(++r==arr.size()) return -1;
            q1Sum+=arr[r];
            answer++;
        }
    }
    
    return answer;
}