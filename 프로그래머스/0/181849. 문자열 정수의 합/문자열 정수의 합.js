function solution(num_str) {
    return [...num_str].reduce((s,e)=>+e+s,0);
}