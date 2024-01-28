function solution(arr) {
    return [...arr, ...Array((1<<Math.ceil(Math.log2(arr.length)))-arr.length).fill(0)]
}