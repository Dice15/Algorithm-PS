function solution(num, total) {
    return Array.from({length: num}, (_,i)=>i + (total - num * (num - 1) / 2) / num);
}