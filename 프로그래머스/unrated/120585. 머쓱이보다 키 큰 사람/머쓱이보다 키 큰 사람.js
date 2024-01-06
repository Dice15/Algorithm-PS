function solution(array, height) {
    return array.sort((a, b)=>b-a).reduce((cnt, val)=>cnt+Number(val>height), 0)
}