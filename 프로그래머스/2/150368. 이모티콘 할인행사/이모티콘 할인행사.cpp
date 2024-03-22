#include <bits/stdc++.h>
using namespace std;


void solve(int eIdx, vector<int> &sDiscounts, vector<int> &eDiscounts, vector<int> &emoticons, vector<vector<int>> &users, vector<int> &answer){
    if(eIdx==emoticons.size()){
        int pCnt=0;
        int sum=0;   
        for(auto &user : users){
            int tSum=0;
            for(int i=0;i<emoticons.size();i++){
                if(user[0]<=sDiscounts[i]){
                    tSum+=(emoticons[i]/100)*(100-sDiscounts[i]);
                }
            }
            if(user[1]<=tSum){
                pCnt++;
            }else{
                sum+=tSum;
            }
        }
        if(answer[0]<pCnt){
            answer[0]=pCnt;
            answer[1]=sum;
        }else if(answer[0]==pCnt && answer[1]<sum){
            answer[1]=sum;
        }
    }else{
        for(int i=0;i<4;i++){
            sDiscounts[eIdx]=eDiscounts[i];
            solve(eIdx+1, sDiscounts, eDiscounts, emoticons, users, answer);
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> eDiscount={10, 20, 30, 40};
    vector<int> answer(2, -1e9);
    vector<int> sDiscounts(emoticons.size());
    solve(0, sDiscounts, eDiscount, emoticons, users, answer);
    return answer;
}