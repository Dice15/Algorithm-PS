function solution(str, n1, n2) {
    return [...str].map((s,i)=> i===n1 ? str[n2] : i===n2 ? str[n1] : s).join("");
}