function solution(numbers) {
    return numbers.sort((a, b) => b-a).reduce((mul, val, idx)=>mul*(idx<2 ? val : 1));
}