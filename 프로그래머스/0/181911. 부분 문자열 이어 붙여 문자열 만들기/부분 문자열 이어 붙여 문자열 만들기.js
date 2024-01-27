function solution(my_strings, parts) {
    return my_strings.reduce((s,e,i)=>s+e.substring(parts[i][0], parts[i][1]+1),"");
}