function solution(n, numlist) {
    return numlist.filter((e)=>!Boolean(e%n));
}