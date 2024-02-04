#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer, comb(numbers.size()-2);
    comb.resize(numbers.size(), 1);
    
    set<int> result;
    do{
        int num=0;
        for(int i=0;i<comb.size();i++){
            if(comb[i]) num+=numbers[i];
        }
        result.insert(num);
    }while(next_permutation(comb.begin(), comb.end()));

    for(auto &e : result)
        answer.push_back(e);
    
    return answer;
}