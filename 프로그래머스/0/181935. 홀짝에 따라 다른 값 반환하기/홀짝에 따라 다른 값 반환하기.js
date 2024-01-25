function solution(n) {
    return Array.from({length:~~((n+1)/2)}, (_, i) => ((i*2)+2-n%2)**(2-n%2)).reduce((sum, e)=>sum+e, 0);
}