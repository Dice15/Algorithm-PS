function solution(my_string) {
    return my_string.match(/\d/g).map(e=>+e).sort((a,b)=>a-b)
}