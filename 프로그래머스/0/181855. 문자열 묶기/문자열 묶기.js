function solution(strArr) {
    return strArr.reduce((c,e)=>(c[e.length]++, c), Array.from({length:31}, ()=>0)).reduce((m,e)=>Math.max(m,e), 0);
}