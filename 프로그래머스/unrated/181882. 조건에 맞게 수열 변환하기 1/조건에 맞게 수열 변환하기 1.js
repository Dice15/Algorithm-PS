function solution(arr) {
    return arr.map((val)=>Math.floor(val*(val%2 ? val<50 ? 2 : 1 : val>=50 ? 0.5 : 1)));
}