#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    for(int i=10000;i>=0;i--){
        if(i<=citations.end() - lower_bound(citations.begin(), citations.end(), i)) return i;
    }
    return 0;
}