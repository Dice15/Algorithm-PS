function solution(num_list) {
    return [num_list.length-num_list.reduce((cnt, val)=>cnt+val%2,0), num_list.reduce((cnt, val)=>cnt+val%2,0)];
}