function solution(arr) {
    return arr.reduce((res, e)=>[...res, ...Array.from({length:e}, ()=>e)], [])
}