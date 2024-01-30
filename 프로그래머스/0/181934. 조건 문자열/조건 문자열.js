function solution(ineq, eq, n, m) {
    return +(ineq==='<' ? (eq==='=' ? n<=m : n<m) : (eq==='=' ? n>=m : n>m));
}