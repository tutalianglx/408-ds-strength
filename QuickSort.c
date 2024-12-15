//划分
int Partition(int arr[],int L,int R){
  int mid = arr[0];//取最左侧元素为中枢元素
  while(L < R){
    while(arr[R] >= mid && L<R) R--;
    arr[L] = arr[R];
    while(arr[L] <= mid && L<R) L++;
    arr[R] = arr[L];
  }
  arr[L] = mid;
  return L;
}

//快速排序
void QuickSort(int arr[],int L,int R){
  if(L >= R) return;
  int M = Partition(arr,L,R);
  QuickSort(arr,L,M-1);
  QuickSort(arr,L+1,R);
}
