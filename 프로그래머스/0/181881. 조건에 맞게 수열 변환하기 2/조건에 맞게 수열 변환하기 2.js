function solution(curr, prev=[], x=0) {
    return curr.every((e,i)=>e===prev[i]) ? x-1 : solution(curr.map(e => (e<50 && e%2) ? e*2+1 : (e>=50 && (e+1)%2) ? e/2 : e), curr, x+1)
}