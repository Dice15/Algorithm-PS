function solution(num_list) {
    return Object.values(num_list.reduce((sum, n)=>n%2 ? {...sum, o:sum.o*10+n} : {...sum, e:sum.e*10+n}, {e:0, o:0})).reduce((sum, n)=>sum+n, 0)
}

