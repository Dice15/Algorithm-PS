function solution(i, j, k) {
    return Array.from({length:j-i+1},(_,t)=>t+i).join('').match(new RegExp(`${k}`,'g'))?.length||0
}

