function solution(str) {
    return [...str].reduce((r,_,i)=>[...r, str.slice(i)],[]).sort();
}