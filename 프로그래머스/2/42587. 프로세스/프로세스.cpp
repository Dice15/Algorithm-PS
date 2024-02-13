#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

int solution(vector<int> p, int loc) {
    queue<int> q;
    priority_queue<int> pq;
    
    for(int i=0;i<p.size();i++){
        q.push(i);
        pq.push(p[i]);
    }
    
    int cnt=0;
    while(!q.empty()){
        if(p[q.front()]==pq.top()){       
            cnt++;
            if(q.front()==loc) break;
            q.pop();
            pq.pop();
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }
    
    return cnt;
}