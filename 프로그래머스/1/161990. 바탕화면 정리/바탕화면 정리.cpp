#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> a={(int)1e9, (int)1e9, (int)-1e9, (int)-1e9};

    for(int i=0;i<wallpaper.size();i++){
        for(int j=0;j<wallpaper[i].size();j++){
            if(wallpaper[i][j]=='.') continue;
            a[0]=min(a[0], i);
            a[1]=min(a[1], j);
            a[2]=max(a[2], i+1);
            a[3]=max(a[3], j+1);        
        }
    }
    
    return a;
}