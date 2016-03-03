void mergeTwoSortedArrays(int m, int n, int A[], int B[], int C[]) {
    int i, j, k;
    i = 0;
    j = 0;
    k = 0;
    while (i < m && j < n) {
        if (A[i] <= B[j]) {
            C[k] = A[i];
            i++;
        } else {
            C[k] = B[j];
            j++;
        }
        k++;
    }
    if (i < m) {
        for (int p = i; p < m; p++) {
            C[k] = A[p];
            k++;
        }
    } else {
        for (int p = j; p < n; p++) {
            C[k] = B[p];
            k++;
        }
    }
}
int main()
{
    int numbers[] = {8, 2, 5, 1, 0};
    sortingIntegers(numbers, 0, 5);
    for (int i=0;i<5;i++)
        cout << numbers[i] << ' ';
    return 0;
}

void sortingIntegers(int *list, int left, int size) {
    if (left == size)
        return;
    int smallest = smallestIndex(list, left, size);
    int c = list[smallest];
    list[smallest] = list[left];
    list[left] = c;
    sortingIntegers(list, left+1 ,size);
}

int smallestIndex(int *array, int left, int size) {
    int smallest = array[left];
    int smIndex = left;
    for (int i = left+1; i < size; i++) {
        if (array[i] < smallest) {
            smallest = array[i];
            smIndex = i;
        }
    }
    return smIndex;
}
