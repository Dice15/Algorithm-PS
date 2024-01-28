function solution(list, n) {
    return Array.from({length:list.length/n}).map((_,i)=>list.slice(i*n,i*n+n));
}