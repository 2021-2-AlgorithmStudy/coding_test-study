const b = {
    a: "b",
    b: "hi b"
}
const test = {
    b: "test b"
}
test[b.a] = "test2 b";
console.log(test.b);