function solution(keys, board, [mx, my]=[~~(board[0]>>1), ~~(board[1]>>1)]) {
    return keys.reduce(([x,y],k)=> k==='left' ? [Math.max(-mx,x-1),y] : k==='right' ? [Math.min(mx,x+1),y] : k==='up' ? [x,Math.min(my,y+1)] : k==='down' ? [x,Math.max(-my,y-1)] : [x,y], [0, 0]);
}