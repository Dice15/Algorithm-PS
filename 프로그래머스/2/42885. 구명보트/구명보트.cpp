#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end(), greater<int>());
    int answer = 0;
    for(int i=0,j=people.size()-1;i<=j;i++){
        answer++;
        if(people[i]+people[j]<=limit) j--;
    }
    return answer;
}