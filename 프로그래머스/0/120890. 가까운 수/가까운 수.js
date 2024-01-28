function solution(arr, n) {  
    return arr.sort((a,b)=>Math.abs(a-n) - Math.abs(b-n) || a-b)[0]
    //return arr.sort((a,b)=>a-b).reduce((r,e)=>Math.abs(n-e)<r[0] ? [Math.abs(n-e), e] : r,[2e18,2e18])[1]
}