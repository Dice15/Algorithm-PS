const solution = (arr, n) => arr.map((e, i)=>(arr.length+i)%2 ? e+n : e);
