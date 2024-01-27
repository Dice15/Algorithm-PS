function solution(myString) {
    return (myString+"x").match(/[^x]+/g).sort()
}