function solution(n, [a,b,c], list) {
    return list=list.slice(n!==1 ? a : 0, n!==2 ? b+1 : list.length), n===4 ? list.filter((_,i)=>i%c===0) : list;
}