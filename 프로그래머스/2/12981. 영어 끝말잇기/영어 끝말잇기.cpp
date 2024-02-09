#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_set<string> h; 
    for(int i=0;i<words.size();i++){
        if(h.find(words[i])!=h.end() || (i>0 && words[i-1].back()!=words[i].front())){
            return vector<int>{(i%n)+1, (i/n)+1};
        }
        h.insert(words[i]);
    } 
    return vector<int>{0,0};
}