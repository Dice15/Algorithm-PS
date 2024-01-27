function solution(arrs) {
    return +arrs.every((arr,i)=>arr.every((e,j)=>arrs[j][i]===e))
}