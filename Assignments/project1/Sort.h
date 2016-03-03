#ifndef SORT_H
#define SORT_H

template <class T>
class Sort {
  public:
    Sort(int);
    void add(T);
    virtual void sort(void)=0;
    void display(void);
    virtual ~Sort();
  protected:
    T* arr;
    int i;
    const int m_size;
};
#endif
