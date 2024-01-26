function solution(arr) {
    return arr.map((e)=>Array.from({length:e}, ()=>e).join(",")).join(",").split(",").map((e)=>+e);
}