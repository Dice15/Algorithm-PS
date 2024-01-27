function solution(myString) {
    return [...myString.toLowerCase()].reduce((s,e)=>s+(e==="a" ? "A" : e), "");
}