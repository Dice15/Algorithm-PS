function solution(n, x=0, y=-1, d=0, dir=[[0, 1], [1, 0], [0, -1], [-1, 0]], move=(b)=>{(0<=x+dir[d][0] && x+dir[d][0]<n && 0<=y+dir[d][1] && y+dir[d][1]<n && !b[x+dir[d][0]][y+dir[d][1]]) ? (x+=dir[d][0], y+=dir[d][1]): (d=(d+1)%4, move(b))}) {
    return Array(n*n).fill().reduce((b,_,i)=>(move(b), b[x][y]=i+1, b), Array.from(Array(n), ()=>Array(n)))
}
                                                                                      
                                                                               