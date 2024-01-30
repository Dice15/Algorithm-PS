function solution(arr, len=Math.max(arr.length, arr[0].length)) {
    return Array.from({length:len}, (_,i)=>Array.from({length:len}, (_,j)=>arr.at(i)?.at(j) || 0));
}