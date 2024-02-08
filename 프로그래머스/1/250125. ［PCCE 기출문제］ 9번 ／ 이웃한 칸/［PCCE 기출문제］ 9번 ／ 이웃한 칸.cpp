#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0, mh=board.size(), mw=board[0].size(); 
    for(auto &[x, y] : vector<pair<int,int>>{{-1,0}, {1,0}, {0,-1}, {0,1}}){
        auto [nh, nw]=pair(h+x, w+y);
        if(0<=nh && nh<mh && 0<=nw && nw<=mw && board[nh][nw]==board[h][w]) answer++;
    }
    return answer;
}