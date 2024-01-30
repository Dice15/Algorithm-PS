function solution(score, lank=score.map(([e,m])=>e+m).sort((a,b)=>b-a)) {
    return score.map(([e,m])=>lank.indexOf(e+m)+1);
}