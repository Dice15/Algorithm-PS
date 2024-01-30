function solution(arr, stk=[], insert=(stk, value)=>{ (stk.length===0 || stk.at(-1) < value) ? stk.push(value) : (stk.pop(), insert(stk, value)) }) {
    return arr.forEach(e=>insert(stk, e)), stk
}