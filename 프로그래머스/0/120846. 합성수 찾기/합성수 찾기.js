function solution(n) {
    return Array.from({length:n},(_,i)=>i+1).filter((e,i)=>Array.from({length:e},(_,j)=>j+1).filter(j=>e%j===0).length>2).length;
}