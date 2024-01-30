function solution(a, b, gcd=(a,b)=>b===0 ? a : gcd(b, a%b), div=(n,d)=>n%d ? n : div(n/d, d)) {
    return +(div(div(b/gcd(a,b), 2), 5) > 1)+1
}