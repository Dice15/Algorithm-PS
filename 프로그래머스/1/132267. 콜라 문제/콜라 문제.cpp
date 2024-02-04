#include <bits/stdc++.h>
using namespace std;

int solution(int a, int b, int n) {
    int answer = 0, pn=1e9;
    while(pn!=n){
        pn=n;
        answer+=(n/a)*b;
        n=(n/a)*b + n%a;    
    }
    return answer;
}