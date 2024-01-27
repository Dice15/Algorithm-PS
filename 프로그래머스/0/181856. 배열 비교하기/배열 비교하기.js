function solution(arr1, arr2) {
    return Math.sign(arr1.length-arr2.length || arr1.reduce((s,e)=>s+e)-arr2.reduce((s,e)=>s+e))
}