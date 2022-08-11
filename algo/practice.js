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
  const characters = "012";
  var s = "";
  for (let i = 0; i < 300; i++) {
    s += characters.charAt(Math.floor(Math.random() * characters.length)) + ",";
  }
  return s;
};

console.log(getStr());
