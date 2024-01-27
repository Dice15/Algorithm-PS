function solution(str) {
    return Array.from({length:str.length}).map((_,i)=>str.slice(i)).sort();
}