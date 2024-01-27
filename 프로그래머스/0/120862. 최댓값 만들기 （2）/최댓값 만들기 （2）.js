function solution(numbers) {
    return numbers.reduce((r1,n1,i)=>Math.max(r1,numbers.reduce((r2,n2,j)=>i==j?r2:Math.max(r2, n1*n2),-2e18)),-2e18);
}