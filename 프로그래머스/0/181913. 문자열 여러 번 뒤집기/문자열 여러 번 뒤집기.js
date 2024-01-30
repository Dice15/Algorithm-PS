function solution(str, queries) {
    return queries.reduce((r,[s, e])=>(r.splice(s, e-s+1, ...r.slice(s,e+1).reverse()), r), [...str]).join('')
}