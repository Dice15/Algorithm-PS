function solution(arr, queries) {
    return queries.reduce((res,[s,e,k])=>[...res, [...arr.slice(s, e+1), k].sort((a,b)=>a-b).find(e=>e>k) || -1], []);
}