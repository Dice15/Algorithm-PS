function solution(num, k) {
    return [...num.toString()].findIndex(e=>+e===k)+1||-1;
}