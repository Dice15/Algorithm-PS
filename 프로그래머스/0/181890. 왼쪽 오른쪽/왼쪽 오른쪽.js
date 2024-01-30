function solution(list, l=list.indexOf('l'), r=list.indexOf('r')) {
    return (l!==-1 && (l<r || r===-1)) ? list.slice(0, l) : (r!==-1 && (r<l || l===-1)) ? list.slice(r+1) : []
}