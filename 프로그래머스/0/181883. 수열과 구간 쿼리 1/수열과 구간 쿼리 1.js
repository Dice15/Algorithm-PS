function solution(arr, queries) {
    return queries.reduce((r,[s,e])=>(Array.from({length:e-s+1},(_,i)=>i+s).forEach((i)=>r[i]++),r),arr);
}