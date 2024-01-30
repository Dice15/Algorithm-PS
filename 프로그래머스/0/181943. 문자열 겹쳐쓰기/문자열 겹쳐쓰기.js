function solution(str, over, s) {
    return [...str].slice(0, s).join('')+over+[...str].slice(s+over.length).join('')
}