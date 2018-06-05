#include <iostream>
using namespace std;

// 快排
int partition(int data[], int left, int right)
{
    int i = left - 1, temp = data[right];
    for(int j = left; j < right; j++)
    {
        if(data[j] <= temp)
        {
            std::swap(data[++i], data[j]);
        };
    }
    std::swap(data[i + 1], data[right]);
    return i + 1;
}

void quick_sort(int data[], int start, int end)
{
    if(start >= end) return;
    int i = partition(data, start, end);
    quick_sort(data, start, i - 1);
    quick_sort(data, i + 1, end);
}

int main()
{
    int data[] = {7, 5, 8, 1, 0, 9, 6};
    quick_sort(data, 0, 6);

    for(int i = 0; i < 6; i++)
    {
        cout << data[i] << endl;
    }
}
