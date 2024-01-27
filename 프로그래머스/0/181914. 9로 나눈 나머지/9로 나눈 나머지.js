function solution(num) {
    return [...num].reduce((s,e)=>s+(+e),0)%9;
}