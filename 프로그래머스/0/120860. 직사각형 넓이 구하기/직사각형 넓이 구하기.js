function solution(dots, [mx, my]=[...dots[0]]) {
    return Math.abs(dots.slice(1).reduce((r,[x,y])=> r * ((mx!==x && my!==y) ? 1 : mx===x ? my-y : mx-x), 1));
}