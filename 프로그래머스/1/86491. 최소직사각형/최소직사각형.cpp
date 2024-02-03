#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int v=0,h=0;
    for(auto &size : sizes){
        v=max(v, max(size[0], size[1]));
        h=max(h, min(size[0], size[1]));
    }
    return v*h;
}