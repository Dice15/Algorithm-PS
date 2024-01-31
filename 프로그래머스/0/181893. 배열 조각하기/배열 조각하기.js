function solution(arr, query) {
    return query.reduce((r,e,i)=>i%2 ? r.slice(e) : r.slice(0,e+1), arr);
}