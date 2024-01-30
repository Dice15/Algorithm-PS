function solution(numbers, strings=["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]) {
    return +strings.reduce((r,s,i)=>r.replaceAll(new RegExp(`${s}`, 'g'), i), numbers)
}