function solution(arr, m=-1) {
    return arr=arr.reduce((c,e)=>(m=Math.max(++c[e], m), c), Array(1000).fill(0)).reduce((r,e,i)=>e===m ? [...r, i] : r, []), arr.length === 1 ? arr[0] : -1
}