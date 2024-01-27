function solution(n) {
    return Array.from({length:n},(_,i)=>i+1).filter(e=>n%e===0);
}