#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int maxHealth=health;
    
    for(int i=0,t=0,a=0; i<attacks.size(); i+=(attacks[i][0]==t++), a%=bandage[0]){
        if(attacks[i][0]==t){
            health-=attacks[i][1];
            if(health<=0) break;
            a=0;
        }
        else{
            health=min(maxHealth, health+bandage[1]+(++a==bandage[0] ? bandage[2] : 0));
        }
    }
    
    return health<=0 ? -1 : health;
}