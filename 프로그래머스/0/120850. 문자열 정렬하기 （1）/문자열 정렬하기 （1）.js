function solution(my_string) {
    return [...my_string.replace(/\D+/g,"")].map(e=>+e).sort((a,b)=>a-b);
}