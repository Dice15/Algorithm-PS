#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> a) {
    a.push_back(a.back());
    vector<int> count(500001, 0), selectIdx(500001, -2e8);
    
    int answer = 0;
    for(int i=0;i<(int)a.size()-1;i++){    
            if(selectIdx[a[i]]<i-1){
                if(i>0 && a[i-1]!=a[i]){
                    count[a[i]]++;
                    selectIdx[a[i]]=i-1;
                }else if(a[i+1]!=a[i]) {
                    count[a[i]]++;
                    selectIdx[a[i]]=i+1;
                }
            }else {
                if(a[i+1]!=a[i]) {
                    count[a[i]]++;
                    selectIdx[a[i]]=i+1;
                }
            }
        answer=max(answer, count[a[i]]*2);
    }
    
    return answer;
}