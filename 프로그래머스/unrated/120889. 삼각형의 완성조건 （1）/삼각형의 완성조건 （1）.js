function solution([a, b, c]) {
    return Number(!(a<b+c&&b<a+c&&c<a+b))+1
}