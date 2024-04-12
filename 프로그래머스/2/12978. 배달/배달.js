function floyd(n, dist) {
    for(let m=0;m<n;m++){
        for(let i=0;i<n;i++){
            for(let j=0;j<n;j++){
                dist[i][j]=Math.min(dist[i][j], dist[i][m]+dist[m][j]);
            } 
        }
    }
}

function solution(N, road, K) {
    const dist=Array.from({length:N}, ()=>Array.from({length:N}, ()=>Number(1e9)));     
    road.forEach(([a,b,c])=>{
        const minCost=Math.min(Math.min(dist[a-1][b-1], dist[b-1][a-1]), c);
        dist[a-1][b-1]=dist[b-1][a-1]=minCost;
    });
    for(let i=0;i<N;i++) dist[i][i]=0;
    
    floyd(N, dist);
    return dist[0].reduce((cnt, e)=>cnt+(e<=K), 0);
}