function solution(list, n) {
    return list.sort((a,b)=>Math.abs(a-n)-Math.abs(b-n) || b-a);
}