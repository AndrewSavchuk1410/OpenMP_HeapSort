#include <iostream>
#include <time.h>
#include <chrono>
#include<stdlib.h>

using namespace std;
#define MAX 10000000
double RunTime = 0;
int arr[MAX];

void Heapify(int n, int i) {
    clock_t t1, t2;
    t1 = clock();

    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        Heapify(n, largest);
    }

    t2 = clock();

    //RunTime = RunTime + ((t2 - t1) / (double)CLOCKS_PER_SEC);
}

// main function to do heap sort
void HeapSort(int n)
{
    int k = 0;
    clock_t start, stop;
    start = clock();

//#pragma omp parallel sections num_threads(12)
    {
//#pragma omp section
        {
            k - k + 1;
            for (int i = n / 2 - 1; i >= 0; i--)
                Heapify(n, i);
        }
//#pragma omp section
        {
            k = k + 1;

            for (int i = n - 1; i >= 0; i--)
            {
                // Move current root to end
                swap(arr[0], arr[i]);

                // call max heapify on the reduced heap
                Heapify(i, 0);
            }
        }}
    stop = clock();
    RunTime = RunTime + ((stop - start) / (double)CLOCKS_PER_SEC);
}

void printArray()
{
    for (int i = 0; i < MAX; ++i)
        cout << arr[i] << " " << endl;
    cout << "\n";
}

int main()
{
    srand(time(NULL));
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = rand();
    }
    auto start = std::chrono::system_clock::now();
    HeapSort(MAX);
    auto end = std::chrono::system_clock::now();
    //printArray();
    //auto time = end - start;
    auto time2 = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

    cout << "Runtime: " << time2 << endl;
    return(0);
}