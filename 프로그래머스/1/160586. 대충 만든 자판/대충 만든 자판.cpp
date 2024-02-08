#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> alpha(26, 1e9);
    
    for(auto &key : keymap){
        for(int i=0;i<key.size();i++){
            alpha[key[i]-65]=min(alpha[key[i]-65], i+1);
        }
    }
    
    vector<int> answer;
    for(auto &target : targets){
        int cnt=0;
        for(int i=0;i<target.size();i++){
            if(alpha[target[i]-65]==(int)1e9){
                cnt=-1;
                break;
            }
            cnt+=alpha[target[i]-65];
        }
        answer.push_back(cnt);
    }   
    return answer;
}