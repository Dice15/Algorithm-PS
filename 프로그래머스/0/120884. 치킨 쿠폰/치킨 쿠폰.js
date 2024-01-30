function solution(chicken) {
    return chicken<10 ? 0 : ~~(chicken/10) + solution(~~(chicken/10) + chicken%10);
}