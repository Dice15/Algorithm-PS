function solution(arrs) {
    return arrs.reduce((r1,arr,i)=>r1&arr.reduce((r2,e,j)=>r2&arrs[j][i]===e,true),true);
}