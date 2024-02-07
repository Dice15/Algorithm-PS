#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    char x='\0';
    int answer=-1, xCnt=0, nCnt=0;
    
    for(int i=0;i<s.size();i++){
        if(xCnt==nCnt){
            xCnt=1;
            nCnt=0;
            x=s[i];
            answer++;
        }
        else{
            if(x==s[i]) xCnt++;
            else nCnt++;
        }
    }
    
    return answer+1;
}