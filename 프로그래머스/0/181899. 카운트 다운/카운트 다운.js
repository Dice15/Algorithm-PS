function solution(s, e) {
    return Array.from({length:s-e+1},(_,i)=>i+e).sort((a,b)=>b-a);
}