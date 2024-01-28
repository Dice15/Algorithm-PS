// function solution(list, cnt=0) {
//     return list.some(v=>v!==1) ? solution(list, list.reduce((s,v,i)=>(v!==1 ? (list[i]=~~(v/2), s+1) : s),cnt)) : cnt
// }

function solution(list){
    return list.reduce((s,e)=>s+e.toString(2).length-1,0)
}