#include <bits/stdc++.h>
using namespace std;

int div(int cx, int cy, int len, vector<vector<int>> &arr, vector<int> &cnt){
    if(len==1) return arr[cx][cy];
    int nLen = len/2;
    int res1 = div(cx, cy, nLen, arr, cnt);
    int res2 = div(cx+nLen, cy, nLen, arr, cnt);
    int res3 = div(cx, cy+nLen, nLen, arr, cnt);
    int res4 = div(cx+nLen, cy+nLen, nLen, arr, cnt);
    if(res1==res2 && res1==res3 && res1==res4) return res1;
    cnt[res1]++;
    cnt[res2]++;
    cnt[res3]++;
    cnt[res4]++;
    return 2;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(3);
    answer[div(0, 0, arr.size(), arr, answer)]++;
    answer.resize(2);
    return answer;
}