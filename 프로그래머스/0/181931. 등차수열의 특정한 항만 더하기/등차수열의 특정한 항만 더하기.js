function solution(a, d, included) {
    return included.reduce((s,e,i)=>e?s+a+d*i:s,0);
}