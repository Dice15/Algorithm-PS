function solution(spell, dic) {
    return +(dic.filter(w=>spell.length === spell.filter(s=>(w.match(new RegExp(`${s}`, 'g'))?.length || 0)===1).length).length===0)+1;
}