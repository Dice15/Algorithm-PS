function solution(str) {
    return str.replaceAll(' ','').match(/(\+|\-)?\d+/g).reduce((s,e)=>+e+s,0)
}