#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> s;
    sort(phone_book.begin(), phone_book.end(), greater<string>());
    for(auto &p : phone_book){
        if(s.find(p)!=s.end()) return false;
        string sub="";
        for(int i=0;i<p.size()-1;i++){
            sub+=p[i];
            s.insert(sub);
        }      
    }
    return true;
}