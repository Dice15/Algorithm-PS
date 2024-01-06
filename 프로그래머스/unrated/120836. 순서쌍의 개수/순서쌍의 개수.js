function solution(n) {
    return Array.from({length:n}, (_, index)=>index+1).reduce((cnt, val)=>cnt+(n%val===0));
}