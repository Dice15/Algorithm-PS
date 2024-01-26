function solution(numbers, n) {
    return numbers.reduce((sum, e)=>sum>n?sum:sum+e, 0);
}