function solution(s, e) {
    return Array.from({length:s-e+1},(_,i)=>s-i);
}