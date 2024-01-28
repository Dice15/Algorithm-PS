function solution(my_string, indices) {
    return indices.reduce((r,i)=>(r[i]='',r),[...my_string]).join('');
}