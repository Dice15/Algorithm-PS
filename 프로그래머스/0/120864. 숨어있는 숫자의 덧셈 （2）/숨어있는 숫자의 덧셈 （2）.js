function solution(str) {
    return str.match(/\d+/g)?.reduce((s,e)=>+e+s,0)||0;
}