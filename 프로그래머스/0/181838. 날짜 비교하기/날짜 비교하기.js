function solution([y1,m1,d1], [y2,m2,d2]) {
    return +(`${y1}${m1.toString().padStart(2,'0')}${d1.toString().padStart(2,'0')}`<`${y2}${m2.toString().padStart(2,'0')}${d2.toString().padStart(2,'0')}`);
}