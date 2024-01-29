function solution(str) {
    return Array.from({length:52},(_,i)=>String.fromCharCode(i<26 ? i+65 : i+71)).map(e=>str.match(new RegExp(`${e}`,'g'))?.length || 0);
}