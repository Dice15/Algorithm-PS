function solution(array) {
    return array.reduce((r,e,i)=>r[0]<e?[e,i]:r,[-1,-1]);
}