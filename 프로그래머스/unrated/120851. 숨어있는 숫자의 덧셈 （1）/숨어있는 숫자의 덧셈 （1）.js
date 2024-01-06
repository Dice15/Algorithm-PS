function solution(my_string) {
    return [...my_string].reduce((sum, val)=>sum+(parseInt(val)||0),0);
}