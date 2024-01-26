function solution(hp) {
    const v1=~~(hp/5);
    const v2=~~((hp-v1*5)/3);
    const v3=hp-(v1*5)-(v2*3);
    return v1+v2+v3;
}