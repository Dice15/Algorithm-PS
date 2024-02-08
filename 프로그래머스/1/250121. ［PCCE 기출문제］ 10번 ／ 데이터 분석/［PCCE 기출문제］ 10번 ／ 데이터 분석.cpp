#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<pair<int,int>> newData;
    
    int ext_idx=map<string,int>{{"code", 0}, {"date", 1}, {"maximum", 2}, {"remain", 3}}[ext];
    int sort_idx=map<string,int>{{"code", 0}, {"date", 1}, {"maximum", 2}, {"remain", 3}}[sort_by];
    
    for(int i=0;i<data.size();i++){
        if(data[i][ext_idx] < val_ext){
            newData.push_back({data[i][sort_idx], i});
        }      
    }
    
    sort(newData.begin(), newData.end());
    
    vector<vector<int>> answer;
    for(auto &[v, i] : newData){
        answer.push_back(data[i]);
    }   
    return answer;
}