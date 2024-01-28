function solution(arr, queries) {
    return queries.reduce((r,[s,e])=>([r[s],r[e]] = [r[e],r[s]], r), arr);
}