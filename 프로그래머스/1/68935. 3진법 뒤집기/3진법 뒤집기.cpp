#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    int answer = 0, cnt=0;   
    for(int i=n;i;i/=3) cnt++; 
    for(int i=cnt-1;n;i--, n/=3){
        answer+=n%3 * pow(3, i);
    }
    return answer;
}