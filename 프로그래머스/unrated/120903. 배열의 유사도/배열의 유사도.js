function solution(s1, s2) {
    return s1.reduce((cnt, val1)=>cnt+Number(s2.some((val2)=>val1===val2)),0);
}