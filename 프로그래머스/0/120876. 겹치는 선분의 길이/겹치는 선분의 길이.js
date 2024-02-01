function solution(lines) {
    return lines.reduce((c,[a,b])=>(Array(b-a).fill().forEach((_,i)=>c[i+a+100]++) , c), Array(210).fill(0)).filter(e=>e>1).length;
}