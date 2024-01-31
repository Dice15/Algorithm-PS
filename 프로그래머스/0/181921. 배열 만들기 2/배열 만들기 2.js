function solution(l, r, res) {
    return res=Array.from({length:r-l+1},(_,i)=>i+l).filter(e=>e.toString().length===e.toString().match(/0|5/g)?.length), res.length ? res : [-1]
}