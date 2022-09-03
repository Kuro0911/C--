const partition = ({ arr, low, hi }) => {
  let pvt = arr[hi];
  let i = low;
  for (let j = low; j <= hi; j++) {
    if (arr[j] <= pvt) {
      let temp;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i = i + 1;
    }
    return i;
  }
};
const r_partition = ({ arr, low, hi }) => {
  const r = Math.floor(Math.random() * hi) + lo;
  let temp;
  temp = arr[r];
  arr[r] = arr[hi];
  arr[hi] = temp;
  return partition(arr, low, hi);
};
const randomQuickSort = ({ arr, low, hi }) => {
  //   if (low < hi) {
  //     const p = r_partition(arr, low, hi);
  //     quickSort(arr, low, p);
  //     quickSort(arr, p + 1, hi);
  //   }
  return arr;
};

const arr = [5, 4, 3, 2, 1];

// console.log(randomQuickSort(arr={arr}, low={0}, hi={5}));

const getStr = () => {
  let n = 0;
  const characters = "rdwpohqydpqkjkdxhoedvccakjmxuy.*";
  var s = "";
  for (let i = 0; i < 100; i++) {
    // s += characters.charAt(Math.floor(Math.random() * characters.length));
    s += Math.floor(Math.random() * 50) + ",";
  }
  return s;
};

console.log(getStr());

var str = "STR ,1 2 ";
str = str.toLowerCase().replace(/\W/g, "");
var res = str.split("").reverse().join("");
// console.log(res);
