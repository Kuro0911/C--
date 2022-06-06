// Merge sort 2 sorted arrays are made into one ;
#include <bits/stdc++.h>

using namespace std;
void printarr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
};
void merge_Sort_part1(int *a, int low, int mid, int high)
{
    int i, j, k, b[100];
    j = mid + 1;
    i = k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
};
void merge_Sort_part2(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_Sort_part2(a, low, mid);
        merge_Sort_part2(a, mid + 1, high);
        merge_Sort_part1(a, low, mid, high);
    }
};
int main()
{
    int a[] = {54, 87, 10, 84, 32, 69};
    int n = 6;
    printarr(a, n);
    merge_Sort_part2(a, 0, 5);
    printarr(a, n);
    return 0;
}
/*
merge sort in js
export const mergeSort = array => {
    if (array.length === 1) return array;
    const mid = Math.floor(array.length / 2);
    const firstH = mergeSort(array.slice(0 , mid));
    const secondH =  mergeSort(array.slice(mid));
    const sortedArr = [];
    let i = 0,j = 0;
    while(i < firstH.length && j < secondH.length){
        if(firstH[i] < secondH[j]){
            sortedArr.push(firstH[i++]);
        }else{
            sortedArr.push(secondH[j++]);
        }
    }
    while( i < firstH.length) sortedArr.push(firstH[i++]);
    while( j < secondH.length) sortedArr.push(secondH[j++]);
    return sortedArr;
}
*/
// IT is not a inplace algo
// IT is a stable algo