function speakArray() {
    const def=["aya", "ye", "woo", "ma"];
    const res=[];
    for(let i=0;i<4;i++){
        for(let j=0;j<4;j++){
            for(let k=0;k<4;k++){
                for(let t=0;t<4;t++){
                    res.push(def[i]+def[j]+def[k]+def[t]);
                }
                res.push(def[i]+def[j]+def[k]);
            }
            res.push(def[i]+def[j]);
        }
        res.push(def[i]);
    }
    return res;
}


function solution(babblings) {
    const speaks=speakArray();
    return babblings.reduce((sum, babbling)=>{
        //console.log(speaks.some((speak)=>speak===babbling))
        return sum+(speaks.some((speak)=>speak===babbling) ? 1 : 0)
    },0);
}