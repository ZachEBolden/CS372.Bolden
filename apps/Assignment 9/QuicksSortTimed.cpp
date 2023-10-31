#include <iostream>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <algorithm>

template <typename T>
void QuickSort(std::vector<T>&, int, int);

template <typename T>
void Generate(std::vector<T>&,int);

template <typename T>
int Partition(std::vector<T>& v, int, int);

int main()
{
    std::vector<int> testVec1, testVec2, testVec3, testVec4, testVec5;

    //Quick Sort Times
    std::cout << "Using QuickSort" << std::endl;
    Generate(testVec1, 100);
    auto start1 = std::chrono::steady_clock::now();
    QuickSort(testVec1,0, testVec1.size()-1);
    auto end1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elasped_seconds1 = end1 - start1;
    std::cout << " Elasped wall time for " << testVec1.size() << " elements(s) : " << elasped_seconds1.count() << std::endl;

    Generate(testVec2, 500);
    auto start2 = std::chrono::steady_clock::now();
    QuickSort(testVec2,0,testVec2.size()-1);
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elasped_seconds2 = end2 - start2;
    std::cout << " Elasped wall time for " << testVec2.size() << " elements(s) : " << elasped_seconds2.count() << std::endl;

    Generate(testVec3, 1000);
    auto start3 = std::chrono::steady_clock::now();
    QuickSort(testVec3,0, testVec3.size() - 1);
    auto end3 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elasped_seconds3 = end3 - start3;
    std::cout << " Elasped wall time for " << testVec3.size() << " elements(s) : " << elasped_seconds3.count() << std::endl;

    Generate(testVec4, 5000);
    auto start4 = std::chrono::steady_clock::now();
    QuickSort(testVec4,0, testVec4.size() - 1);
    auto end4 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elasped_seconds4 = end4 - start4;
    std::cout << " Elasped wall time for " << testVec4.size() << " elements(s) : " << elasped_seconds4.count() << std::endl;

    Generate(testVec5, 10000);
    auto start5 = std::chrono::steady_clock::now();
    QuickSort(testVec5,0, testVec5.size() - 1);
    auto end5 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elasped_seconds5 = end5 - start5;
    std::cout << " Elasped wall time for " << testVec5.size() << " elements(s) : " << elasped_seconds5.count() << std::endl;
    
    //Sort Times
    std::cout << "Using sort function" << std::endl;

    std::vector<int> testVec6, testVec7, testVec8, testVec9, testVec10;
    Generate(testVec6, 100);
    auto start6 = std::chrono::steady_clock::now();
    std::sort(testVec6.begin(),testVec6.end());
    auto end6 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elasped_seconds6 = end6 - start6;
    std::cout << " Elasped wall time for " << testVec6.size() << " elements(s) : " << elasped_seconds6.count() << std::endl;

    auto start7 = std::chrono::steady_clock::now();
    Generate(testVec7, 500);
    std::sort(testVec7.begin(), testVec7.end());
    auto end7 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elasped_seconds7 = end7 - start7;
    std::cout << " Elasped wall time for " << testVec7.size() << " elements(s) : " << elasped_seconds7.count() << std::endl;

    auto start8 = std::chrono::steady_clock::now();
    Generate(testVec8, 1000);
    std::sort(testVec8.begin(), testVec8.end());
    auto end8 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elasped_seconds8 = end8 - start8;
    std::cout << " Elasped wall time for " << testVec8.size() << " elements(s) : " << elasped_seconds5.count() << std::endl;

    auto start9 = std::chrono::steady_clock::now();
    Generate(testVec9, 5000);
    std::sort(testVec9.begin(), testVec9.end());
    auto end9 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elasped_seconds9 = end9 - start9;
    std::cout << " Elasped wall time for " << testVec9.size() << " elements(s) : " << elasped_seconds9.count() << std::endl;

    auto start10 = std::chrono::steady_clock::now();
    Generate(testVec10, 10000);
    std::sort(testVec10.begin(), testVec10.end());
    auto end10 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elasped_seconds10 = end10 - start10;
    std::cout << " Elasped wall time for " << testVec10.size() << " elements(s) : " << elasped_seconds10.count() << std::endl;

    return 1;
}

//https://slaystudy.com/c-vector-quicksort/
//used this for vector quicksort
template<typename T>
void QuickSort(std::vector<T>& v, int L, int R)
{ 
    if (L < R) 
    {
        int p = Partition(v, L, R);
        QuickSort(v, L, p - 1);
        QuickSort(v, p + 1, R);
    }
    
    
}
template <typename T>
int Partition(std::vector<T>& v, int start, int end) {

    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i) {
        if (v[i] < v[pivot]) {
            std::swap(v[i], v[j]);
            ++j;
        }
    }
    std::swap(v[j], v[pivot]);
    return j;

}

template <typename T>
void Generate(std::vector<T>& testVec, int size)
{
    int rdm;
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        rdm = rand() % 100 + 1;
        testVec.push_back(rdm);
    } 
}