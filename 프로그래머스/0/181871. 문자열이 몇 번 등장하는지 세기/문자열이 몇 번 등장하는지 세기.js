function solution(str, pat) {
    return Array.from({length:str.length}).reduce((s,_,i)=>+str.substr(i).startsWith(pat)+s,0)
}