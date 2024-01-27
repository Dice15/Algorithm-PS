function solution(board, k) {
    return board.reduce((s,r,i)=>s+r.reduce((s,e,j)=>i+j<=k?s+e:s,0),0);
}