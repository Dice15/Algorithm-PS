function solution(str) {
    return [...str].reduce((r,e)=>r.includes(e) ? r : r+e,"");
}