function solution(c) {
    return c[1]-c[0]===c[2]-c[1] ? c.slice(-1)[0] + c[1] - c[0] : c.slice(-1)[0] * (c[1]/c[0]) ;
}