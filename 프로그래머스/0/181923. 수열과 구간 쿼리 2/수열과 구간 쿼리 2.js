function solution(arr, queries) {
    return queries.map(([s,e,k])=>[...arr.slice(s, e+1), k].sort((a,b)=>a-b).find(e=>e>k) || -1, []);
}