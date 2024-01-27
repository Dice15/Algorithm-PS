function solution(order) {
    return [...order.toString()].reduce((s,e)=>+(+e%3===0 && +e!==0)+s,0);
}