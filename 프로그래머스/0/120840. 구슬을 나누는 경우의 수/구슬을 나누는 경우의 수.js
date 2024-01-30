function solution(balls, share, facto=(n)=>(n<1n ? 1n : n * facto(n-1n))) {
    return facto(BigInt(balls)) / (facto(BigInt(balls-share)) * facto(BigInt(share)));
}