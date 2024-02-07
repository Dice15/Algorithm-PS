#include <bits/stdc++.h>
using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i=1;i<=number;i++){
        int cnt=1;
        for(int j=1;j<=i/2;j++){
            if(i%j==0) cnt++;
        }
        answer+=cnt>limit ? power : cnt;
    }
    
    return answer;
}