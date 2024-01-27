function solution(str, m, c) {
    return [...str].filter((_,i)=>(i-c+1)%m===0).join('');
}