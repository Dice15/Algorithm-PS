function solution(my_string, index_list) {
    return index_list.reduce((s, e)=>s+my_string[e],"");
}