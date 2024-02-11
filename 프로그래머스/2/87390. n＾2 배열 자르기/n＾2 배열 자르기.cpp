#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<int> solution(int n, ll left, ll right) {
    vector<int> answer;
    for(ll i=left;i<=right;i++){
        auto [col, row]=pair(i/n+1, i%n+1);
        answer.push_back(row<=col ? col : row);
    }
    return answer;
}