function solution(arr) {
    return arr=arr.reduce((stk,e)=>((stk.length>0 && stk.at(-1)===e ? stk.pop() : stk.push(e)), stk), []), arr.length>0 ? arr : [-1];
}