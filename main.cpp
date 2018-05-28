#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

#include "Vektorius.h++"
#include "Vektorius.cpp"

int main() {

    std::vector<int> v1;
    cout << "Su std::vector :" << endl;
    for(int i = 10000; i <=  100000000; i *= 10)
    {
        auto start = chrono::high_resolution_clock::now();
        for(int j = 0; j < i; j++)
            v1.push_back(i);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "Su " << i << " duomenu trunka - " << elapsed.count() << endl;
        std::vector<int> v1;

    }

    Vector<int> v2;
    cout << "Su Vector :" << endl;
    for(int i = 10000; i <=  100000000; i *= 10)
    {
        auto start = chrono::high_resolution_clock::now();
        for(int j = 0; j < i; j++)
            v2.push_back(i);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "Su " << i << " duomenu trunka - " << elapsed.count() << endl;
        Vector<int> v2;
    }
    return 0;
}