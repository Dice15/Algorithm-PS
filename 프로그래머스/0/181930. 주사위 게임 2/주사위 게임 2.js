function solution(a, b, c) {
    return (a+b+c) * ((a==b || b==c || a==c) ? (a**2+b**2+c**2) : 1) * ((a==b && b==c) ? (a**3+b**3+c**3) : 1);
}