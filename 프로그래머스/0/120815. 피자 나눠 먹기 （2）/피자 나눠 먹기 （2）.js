function solution(n, m=6, g=0) {
    return (m===0 ? g/n/6 : solution(m, n%m, g||n*m));
}