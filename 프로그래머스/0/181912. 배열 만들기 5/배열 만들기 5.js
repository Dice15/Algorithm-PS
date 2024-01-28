function solution(intStrs, k, s, l) {
    return intStrs.map(e=>+e.substr(s,l)).filter(e=>e>k);
}