function solution(my_string, n) {
    return [...my_string].reduce((sum, val)=>sum+val.repeat(n), "");
}