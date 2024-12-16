//二路归并排序
//M为数组A的长度，N为数组B的长度，借助数组C来辅助排序
int Merge(int A[],int M,int B[],int N,int C[]){
    int i,j,k;
    while(i < M && j < N){
        if(A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[i++];
    }
    while(i < M)
        C[k++] = A[i++];
    while(j < N)
        C[k++] = B[i++];
}
