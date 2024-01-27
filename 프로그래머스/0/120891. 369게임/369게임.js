function solution(order) {
    return order.toString().match(/3|6|9/g)?.length||0
}