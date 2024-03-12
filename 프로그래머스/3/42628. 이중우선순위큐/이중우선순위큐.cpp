#include <bits/stdc++.h>
using namespace std;

vector<string> split(string &s, string p){
    regex r(p);
    sregex_token_iterator begin(s.begin(), s.end(), r, -1), end;
    return vector<string>(begin, end);
}

vector<int> solution(vector<string> operations) {
    priority_queue<int> maxPq;
    priority_queue<int, vector<int>, greater<int>> minPq;
    
    for(auto &operation : operations){
        auto op = split(operation, "\\s");
        int num=stoi(op[1]);
        if(op[0]=="I"){      
            maxPq.push(num);
            minPq.push(num);
        }
        else if(!maxPq.empty() && !minPq.empty() && maxPq.top()>=minPq.top()){
            if(num==1) maxPq.pop();
            else minPq.pop();         
        }
        
        if(maxPq.empty() || minPq.empty() || maxPq.top()<minPq.top()){
            while(!maxPq.empty()) maxPq.pop();
            while(!minPq.empty()) minPq.pop();
            continue;
        }
    }
    
    return maxPq.empty() ? vector<int>{0, 0} : vector<int>{maxPq.top(), minPq.top()};
}