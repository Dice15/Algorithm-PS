function solution(n) {
    return Array.from({length:10},(_,i)=>i+1).reduce((r,e,i)=> r[0]*e <=n ? [r[0]*e,i] : r, [1,0])[1]+1
}