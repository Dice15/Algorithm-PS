function solution(myString, pat) {
    return +myString.replaceAll('A','b').replaceAll('B','a').toUpperCase().includes(pat);
}