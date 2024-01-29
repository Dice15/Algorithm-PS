function solution(s) {
    return s.match(/-*\d+(?!(\sZ)|\d)/g)?.reduce((s,e)=>+e+s,0) || 0;
}