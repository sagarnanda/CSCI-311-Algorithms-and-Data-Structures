void mergeSort(int arrayC[],int arrayS[],int arraySize)
{
    m_sort(arrayC,arrayS,0,arraySize -1);
}
void m_sort(int arrayC[],int arrayS[],int left, int right)
{
    int middle;
    cout << " right " << right << " left " << left << endl;
    if(right > left)
    {
        middle = right + left /2;
        m_sort(arrayC,arrayS,left,middle);
        m_sort(arrayC,arrayS,(middle +1),right);
        merge(arrayC, arrayS, left, (middle+1), right);
    }
}

void merge(int numbers[], int temp[], int left, int mid, int right)
{
    int i, left_end, num_elements, tmp_pos;

    left_end = (mid - 1);
    tmp_pos = left;
    num_elements = (right - left + 1);

    while ((left <= left_end) && (mid <= right))
    {
        if (numbers[left] <= numbers[mid])
        {
            temp[tmp_pos] = numbers[left];
            tmp_pos += 1;
            left += 1;
        }
        else
        {
            temp[tmp_pos] = numbers[mid];
            tmp_pos += 1;
            mid += 1;
        }
    }

    while (left <= left_end)
    {
        temp[tmp_pos] = numbers[left];
        left += 1;
        tmp_pos += 1;
    }
    while (mid <= right)
    {
        temp[tmp_pos] = numbers[mid];
