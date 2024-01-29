function solution(order) {
    return order.reduce((s,e)=>s+(e.includes("latte") ? 5000 : 4500), 0);
}