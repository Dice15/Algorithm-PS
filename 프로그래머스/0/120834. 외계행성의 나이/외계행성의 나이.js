function solution(age) {
    return Array.from(String(age), e=>+e).reduce((r,e)=>r+String.fromCharCode(e+97),"");
}