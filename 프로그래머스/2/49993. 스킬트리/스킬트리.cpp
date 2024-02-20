#include <bits/stdc++.h>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;    
    for(auto &skill_tree : skill_trees){
        bool pass = 1;
        vector<int> p(26, 1e9);
        for(int i=0;i<skill_tree.size();i++) p[skill_tree[i]-65] = i;
        for(int i=1;i<skill.size();i++){
            if(p[skill[i-1]-65]>p[skill[i]-65]){
                pass=0;
                break;
            }
        }
        answer+=pass;
    }
    return answer;
}
