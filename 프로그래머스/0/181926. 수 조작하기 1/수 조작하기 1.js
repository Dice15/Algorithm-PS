function solution(n, control) {
    return [...control].reduce((sum, e)=>sum+(e==='w'?1:e==='s'?-1:e==='d'?10:-10), n);
}