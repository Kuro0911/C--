function gen() {
  let res = "";
  for (let i = 1; i <= 1000; i++) {
    // let x = Math.random() * 10000;
    // res += Math.floor(x);
    res += i;
    res += " , ";
  }
  console.log(res);
}

function f() {}
console.log(f(2, 3)(3, 4));
