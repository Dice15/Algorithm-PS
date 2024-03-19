#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> a) {
    vector<int> leftMin(a.size(), 2e18), rightMin(a.size(), 2e18);
    
    leftMin[0]=a[0];
    for(int i=1;i<a.size();i++) leftMin[i]=min(leftMin[i-1], a[i]);
    
    rightMin.back()=a.back();
    for(int i=a.size()-2;i>=0;i--) rightMin[i]=min(rightMin[i+1], a[i]);    
    
    int answer = 0;
    for(int i=0;i<a.size();i++){
        int lCost = i>0 ? leftMin[i]<a[i] : 0;
        int rCost = i<a.size()-1 ? rightMin[i]<a[i] : 0;
        if(lCost+rCost<=1) answer++;
    }
    return answer;
}