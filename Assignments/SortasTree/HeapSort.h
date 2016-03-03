class HeapSort
{
    public:
        HeapSort(int);
        void add(float);
        void sort();
        void display();
        ~HeapSort();
    private:
        int LEFT(int);
        int RIGHT(int);
        void internal_sort(int ,int);
        float* arr;
        int i;
        int m_size;
};
