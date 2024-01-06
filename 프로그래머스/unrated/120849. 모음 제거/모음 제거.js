function solution(my_string) {
    return [...my_string].filter((val)=>!['a','e','i','o','u'].some((alp)=>alp===val)).join("");
}