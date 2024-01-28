function solution(arr, flag) {
    return arr.reduce((r,e,i)=>flag[i] ? [...r, ...Array(e*2).fill(e)] : r.slice(0,r.length-e), []);
}