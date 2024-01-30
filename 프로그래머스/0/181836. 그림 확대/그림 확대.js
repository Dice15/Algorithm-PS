function solution(picture, k) {
    return picture.map(r=>[...r].reduce((s,e)=>(Array(k).fill(0).forEach(()=>s+=e), s), "")).reduce((a,r)=>(Array(k).fill(0).forEach(()=>a.push(r)), a), [])
}