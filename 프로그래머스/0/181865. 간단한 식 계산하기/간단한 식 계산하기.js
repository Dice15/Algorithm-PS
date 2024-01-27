function solution(binomial) {
    return binomial.match(/\d+/g).reduce((r,e)=>binomial.includes('*') ? +r*(+e) : binomial.includes('+') ? +r+(+e) : +r-(+e));
}