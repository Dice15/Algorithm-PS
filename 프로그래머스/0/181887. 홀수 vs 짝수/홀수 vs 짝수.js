function solution(num_list) {
    return Math.max(...num_list.reduce(([o,e],n,i)=>i%2?[o+n,e]:[o,e+n],[0,0]));
}