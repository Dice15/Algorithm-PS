function solution(myString, pat) {
    return myString.match(new RegExp(`.*${pat}`,'g'))[0]
}