function solution(numbers, k) {
    return [...numbers, ...numbers][((k*2)-1)%(numbers.length*2)-1];
}