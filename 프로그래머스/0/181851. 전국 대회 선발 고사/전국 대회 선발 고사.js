function solution(rank, attendance) {
    return rank.map((e,i)=>[e,i]).filter(([e,i])=>attendance[i]).sort((a,b)=>a[0]-b[0]).slice(0,3).reduce((s,[e,i])=>s*100+i, 0);
}