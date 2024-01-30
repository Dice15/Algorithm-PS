function solution(arr, k) {
    return arr=[...new Set(arr)].slice(0, k), arr.length<k ? [...arr, ...Array.from({length:k-arr.length}, ()=>-1)] : arr
}