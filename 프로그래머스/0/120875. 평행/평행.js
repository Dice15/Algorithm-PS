function solution(d, gCmp=([x1, y1], [x2, y2], [x3, y3], [x4, y4])=>(x1-x2) * (y3-y4) === (x3-x4) * (y1-y2)) {
    return +(gCmp(d[0], d[1], d[2], d[3]) || gCmp(d[0], d[2], d[1], d[3]) || gCmp(d[0], d[3], d[1], d[2]))
}


