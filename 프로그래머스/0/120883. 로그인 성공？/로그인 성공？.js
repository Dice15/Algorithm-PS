function solution([uid, upw], db, res) {
    return res=db.find(([id, pw])=>uid===id)?.at(1), res ? res===upw ? 'login' : 'wrong pw' : 'fail';
}