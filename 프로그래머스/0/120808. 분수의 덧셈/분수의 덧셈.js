function solution(n1, d1, n2, d2, n3, d3, gcd=(a, b)=>b===0 ? a : gcd(b, a%b), lcm=(a, b)=>a*b/gcd(a,b)) {
    return d3=lcm(d1, d2), n3=(n1*d3/d1)+(n2*d3/d2), [n3/gcd(n3, d3), d3/gcd(n3, d3)]
}