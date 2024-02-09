#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> elements) {
    vector<int> asum(elements.size()*2+1);  
    vector<bool> check(1000001);
    
    for(int i=1;i<asum.size();i++){
        asum[i]=asum[i-1]+elements[(i-1)%elements.size()];
    }
    
    int answer = 0;
    for(int i=1;i<=elements.size();i++){
        for(int j=i;j<asum.size();j++){
            int v=asum[j]-asum[j-i];
            if(!check[v]){
                answer++;
                check[v]=true;
            }
        }
    }  
    return answer;
}