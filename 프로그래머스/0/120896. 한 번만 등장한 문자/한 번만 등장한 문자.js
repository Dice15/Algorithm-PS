function solution(s) {
    return Array.from({length: 26}, (_, i) => String.fromCharCode(i + 97)).filter(e=>(s.match(new RegExp(`${e}`,'g'))?.length||0)===1).join('');
}