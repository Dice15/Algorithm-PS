function solution(n, sosu=[0, 0, ...Array.from({length:n-1}, (_,i)=>i+2)]) {  
    return sosu.forEach((i) => sosu[i] && Array.from({length:(~~(n/i)-1)}, (_,j)=>j+2).forEach((j)=>sosu[i*j]=0)), sosu.filter((e,i)=>e && n%e===0);
}