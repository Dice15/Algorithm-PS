#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int divGcd(int l, int r, vector<int> &arr){
    if(l==r) return arr[l];
    int mid=(l+r)/2;
    return gcd(divGcd(l, mid, arr), divGcd(mid+1, r, arr));
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int gcdA=divGcd(0, arrayA.size()-1, arrayA);
    int gcdB=divGcd(0, arrayB.size()-1, arrayB);
    
    int answer = 0;
    
    for(int i=sqrt(gcdA),j,iCnt,jCnt;i>=1;i--){
        if(gcdA%i==0){
            j=gcdA/i;
            iCnt=jCnt=0;
            for(auto &e : arrayB){
                if(e%i==0) iCnt++;
                if(e%j==0) jCnt++;
            }
            if(iCnt==0) answer=max(answer, i);
            if(jCnt==0) answer=max(answer, j);
        }
    }
    
    for(int i=sqrt(gcdB),j,iCnt,jCnt;i>=1;i--){
        if(gcdB%i==0){
            j=gcdB/i;
            iCnt=jCnt=0;
            for(auto &e : arrayA){
                if(e%i==0) iCnt++;
                if(e%j==0) jCnt++;
            }
            if(iCnt==0) answer=max(answer, i);
            if(jCnt==0) answer=max(answer, j);
        }
    }
    
    return answer;
}

