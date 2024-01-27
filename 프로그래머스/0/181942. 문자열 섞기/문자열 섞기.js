function solution(s1, s2) {
    return Array.from({length:s1.length}).reduce((s,_,i)=>s+s1[i]+s2[i],"");
}