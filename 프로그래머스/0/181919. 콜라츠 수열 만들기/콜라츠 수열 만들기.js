function solution(n, a=[]) {
    return n!==1?solution(n%2?3*n+1:n/2, [...a, n]):[...a, 1]
}