function solution(box, n) {
    return box.reduce((r,e)=>r*~~(e/n),1);
}