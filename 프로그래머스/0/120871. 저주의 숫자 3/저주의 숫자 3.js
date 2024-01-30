function solution(n, i=1, cnt=0) {
    return cnt===n ? i-1 : solution(n, i+1, cnt+ +!(i%3===0 || `${i}`.includes('3')))
}