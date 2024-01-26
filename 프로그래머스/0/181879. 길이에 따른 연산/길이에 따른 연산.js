function solution(list) {
    return list.reduce((t,e)=>list.length>10?t+e:t*e,+(list.length<=10));
}