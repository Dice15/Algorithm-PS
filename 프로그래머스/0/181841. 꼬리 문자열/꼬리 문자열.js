function solution(str_list, ex) {
    return str_list.reduce((r,s)=>r+(s.includes(ex) ? "" : s),"");
}