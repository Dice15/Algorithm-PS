function solution(poly, v=poly.replaceAll(/(^|\s)(x)/g, '$11x').match(/(\d+(?=x))/g)?.reduce((a,e)=>+e+a, 0), c=poly.match(/\b\d+\b(?!x)/g)?.reduce((a,e)=>+e+a, 0)) {
    return (v && c) ? `${v>1 ? v : ''}x + ${c}` : v ? `${v>1 ? v : ''}x` : `${c}`
}