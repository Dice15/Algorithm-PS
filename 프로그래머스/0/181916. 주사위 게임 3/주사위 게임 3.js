function solution(a, b, c, d, arr=[a,b,c,d], s = [...new Set(arr)].sort((a,b)=>(arr.filter(e=>e===a).length-arr.filter(e=>e===b).length || a-b)).map(e=>[e,arr.filter(a=>a===e).length])) {    
    return s.length === 1 ? 1111*s[0][0] : s.length === 2 ? s[0][1]===1 ? (10*s[1][0]+s[0][0])**2 : (s[1][0]+s[0][0])*Math.abs(s[1][0]-s[0][0]) : s.length === 3 ? s[0][0]*s[1][0] : s[0][0];
}