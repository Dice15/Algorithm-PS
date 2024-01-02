function solution(n) {
    return Array.from({length:Math.floor(n/2)}, (_, idx)=>(idx+1)*2).reduce((sum, value)=>sum+value, 0);
}