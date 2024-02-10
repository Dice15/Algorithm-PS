#include <bits/stdc++.h>
using namespace std;

int solution(string s) { 
    vector<char> stk;
    int answer = 0;   
    
    for(int i=0;i<s.size();i++){
        stk.resize(1, '\0');
        for(int j=i,t=0;t<s.size();j=(++t+i)%s.size()){
            if((stk.back()=='(' && s[j]==')') || (stk.back()=='{' && s[j]=='}') || (stk.back()=='[' && s[j]==']')) stk.pop_back();        
            else stk.push_back(s[j]);
        }
        if(stk.size()==1) answer++;
    }
    
    return answer;
}