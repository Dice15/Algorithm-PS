function solution(myString) {
    return (myString+"x").match(/([a-w]|[y-z])+(?=x)/g).sort()
}