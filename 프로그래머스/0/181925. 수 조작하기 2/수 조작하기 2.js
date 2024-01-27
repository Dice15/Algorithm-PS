function solution(numLog, exp={"1":"w","-1":"s","10":"d","-10":"a"}) {
    return numLog.reduce((r,e,i)=>r + (exp[e-numLog[i-1]] || ""),"");
}