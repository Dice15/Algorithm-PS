function solution(n) {
    return [...n.toString()].reduce((sum, val)=>sum+parseInt(val), 0);
}