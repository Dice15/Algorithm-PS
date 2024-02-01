function solution(b, n = b.length, m = b[0].length, dir=[[-1,0],[1,0],[0,-1],[0,1],[-1,-1],[-1,1],[1,-1],[1,1]]) {
    return b.forEach((r,i)=>r.forEach((c,j)=>c===1 && dir.forEach(([x,y])=>(0<=i+x && i+x<n && 0<=j+y && j+y<m && b[i+x][j+y]===0) && (b[i+x][j+y]=2)))), b.reduce((s,r)=>s+r.reduce((s,c)=>s+ +(c===0), 0), 0);
}