function solution(numbers) {
    return numbers.sort((a, b) => b-a).slice(0, 2).reduce((mul, val)=>mul*val);
}