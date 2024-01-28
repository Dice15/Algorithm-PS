function solution(arr, queries) {
    return queries.reduce((r,[s,e,k])=>(Array.from({length:e-s+1},(_,i)=>i+s).forEach(i=>r[i]+=(i%k===0)), r), arr);
}