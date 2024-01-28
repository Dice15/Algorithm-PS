function solution(str, s, e) {
    return str.substr(0,s)+[...str.substring(s,e+1)].reverse().join('')+str.substr(e+1)
}