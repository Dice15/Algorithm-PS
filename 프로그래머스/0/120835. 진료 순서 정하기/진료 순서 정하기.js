function solution(emergency) {
    return emergency.reduce((o,e,i)=>(o[1][i]=o[0].indexOf(e)+1, o), [[...emergency].sort((a,b)=>b-a),emergency])[1];
}