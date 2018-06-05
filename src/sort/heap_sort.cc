//author: zzq
//堆排序
#include <iostream>


void heapAdjust(int heap[], int length, int p_i)
{
    int temp = heap[p_i];
    int min_i = 2 * p_i + 1;
    while(min_i < length)
    {
        if((min_i + 1) < length && heap[min_i] > heap[min_i + 1]) min_i++;
        if(temp < heap[min_i]) break;
        heap[p_i] = heap[min_i];
        p_i = min_i;
        min_i = 2 * p_i + 1;
    }
    heap[p_i] = temp;
}

void heapSort(int data[], int length)
{
    if(data == NULL || length <= 0) return;
    for(int i = length/2 - 1; i >= 0; i--)
    {
        heapAdjust(data, length, i);
    }

    for(int i = length - 1; i >= 0; --i)
    {
        std::swap(data[0], data[i]);
        heapAdjust(data, i, 0);
    }
}

int main()
{
    int data[] = {97, 76, 65, 49, 49, 38, 27, 13};
    heapSort(data, sizeof(data) / sizeof(data[0]));
    for(int i = 0; i < sizeof(data)/sizeof(data[0]); i++)
    {
        std::cout << data[i] << std::endl;
    }
}
