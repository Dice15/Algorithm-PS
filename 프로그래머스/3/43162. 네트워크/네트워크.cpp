#include <bits/stdc++.h>
using namespace std;

class UnionFind{
public:
    int size;
    vector<int> roots;
    
    UnionFind(int _size) { assign(_size); }
    
    void assign(int _size) {
        size=_size;
        roots.assign(_size, -1); 
    }
    
    int find(int v){
        if(roots[v]<0) return v;
        return roots[v]=find(roots[v]);
    }
    
    bool merge(int u, int v){
        u=find(u);
        v=find(v);
        if(u==v) return false;
        roots[v]+=roots[u];
        roots[u]=v;
        return true;
    }
};


int solution(int n, vector<vector<int>> computers) {
    UnionFind uf(n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!computers[i][j]) continue;
            uf.merge(i, j);
        }
    }
    
    int answer=0;
    for(auto &root : uf.roots){
        if(root<0) answer++;
    }     
    return answer;
}


// class SCC{
// public:
//     int graphSize, sccCnt;
//     vector<vector<int>> graph;
//     vector<int> sccNum;
//     vector<int> dfsCnt;
//     vector<int> dfsStk;
    
//     SCC(int _graphSize=0) { assign(_graphSize); }
    
//     void assign(int _graphSize) {
//         graphSize=_graphSize;
//         sccCnt=0;
//         graph.assign(_graphSize, vector<int>());
//         sccNum.assign(_graphSize, -1);
//         dfsCnt.assign(graphSize, 0);
//         dfsStk.clear();
//     }
    
//     void add_edge(int u, int v) { graph[u].push_back(v); }
    
//     int dfs(int curr, int &cnt) {
//         int minCnt=dfsCnt[curr]=++cnt;
//         dfsStk.push_back(curr);
        
//         for(auto &next : graph[curr]){
//             if(dfsCnt[next]==0) minCnt=min(minCnt, dfs(next, cnt));
//             else if(sccNum[next]==-1) minCnt=min(minCnt, dfsCnt[next]);
//         }
        
//         if(minCnt==dfsCnt[curr]){
//             while(1){
//                 int v=dfsStk.back();
//                 dfsStk.pop_back();
//                 sccNum[v]=sccCnt;
//                 if(v==curr) break;
//             }
//             sccCnt++;
//         }
//         return minCnt;
//     }
    
//     int build() {
//         for(int i=0, cnt=0;i<graphSize;i++){
//             if(sccNum[i]==-1) dfs(i, cnt);
//         }
//         return sccCnt;
//     }
// };

// int solution(int n, vector<vector<int>> computers) {
//     SCC scc(n);
    
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             if(!computers[i][j]) continue;
//             scc.add_edge(i, j);
//         }
//     }
    
//     return scc.build();
// }