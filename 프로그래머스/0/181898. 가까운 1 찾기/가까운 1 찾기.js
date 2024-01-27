function solution(arr, idx) {
    return [...Array.from({length:idx}), ...arr.slice(idx)].indexOf(1);
}