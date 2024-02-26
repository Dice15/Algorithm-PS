#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> order) {
    stack<int> s;
    int j=0;
    for(int i=1;i<=order.size();i++){
        if(i==order[j]) j++;
        else {
            while(!s.empty() && s.top()==order[j]){
                j++;
                s.pop();      
            }
            s.push(i);
        }  
    }
    while(!s.empty() && s.top()==order[j]){
        j++;
        s.pop();          
    }
    return order.size() - s.size();
}