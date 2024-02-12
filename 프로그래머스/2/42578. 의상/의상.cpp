#include <bits/stdc++.h>
using namespace std;
using iter=unordered_map<string,int>::iterator;

int comb(unordered_map<string,int> &cnt, int gob, iter curr){
    if(curr==cnt.end()) return gob;
    return comb(cnt, curr->second * (gob==0 ? 1 : gob), ++curr) + comb(cnt, gob, curr);
}

int solution(vector<vector<string>> clothes) {
    unordered_map<string,int> cnt;
    for(auto &e : clothes) cnt[e[1]]++;
    return comb(cnt, 0, cnt.begin());
}