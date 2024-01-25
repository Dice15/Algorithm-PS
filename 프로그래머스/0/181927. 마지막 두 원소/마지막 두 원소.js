function solution(arr) {
    return [...arr, arr[arr.length-2] < arr[arr.length-1] ? arr[arr.length-1] - arr[arr.length-2] : arr[arr.length-1] * 2];
}