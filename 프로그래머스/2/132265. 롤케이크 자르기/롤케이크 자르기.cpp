#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> topping) {
    vector<bool> checkL(10001), checkR(10001);
    vector<int> countL(topping.size()), countR(topping.size());
    
    for(int i=0,j=(int)topping.size()-1;i<topping.size();i++,j--){
        if(!checkL[topping[i]]) countL[i] = checkL[topping[i]] = true;      
        if(!checkR[topping[j]]) countR[j] = checkR[topping[j]] = true;
        if(i>0) countL[i] += countL[i-1];
        if(j<topping.size()-1) countR[j] += countR[j+1];
    }
    
    int answer=0;
    for(int i=0;i<topping.size()-1;i++) 
        answer += countL[i]==countR[i+1];   
    return answer;
}