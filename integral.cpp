#include "integral.h"
#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <chrono>

Integral::Integral(long long intervals, int threads)  
{
    liczba_przedzialow = intervals; 
    liczba_watkow = threads;         
    wynik_pi = 0;                   
    czas_obliczen = 0;              
}

double Integral::oblicz_czesc(long long start, long long end) 
{
    double dx = 1.0 / liczba_przedzialow; 
    double sum = 0;                      
    for (long long i = start; i < end; i++) 
    {
        double x = (i + 0.5) * dx;       
        sum += 4.0 / (1.0 + x * x);       
    }
    return sum;                           
}

void Integral::oblicz()
{
    auto start = std::chrono::high_resolution_clock::now(); 
    std::vector<std::thread> threads;
    std::vector<double> results(liczba_watkow);  

    for (int i = 0; i < liczba_watkow; i++)  
    {
        long long start_range = i * liczba_przedzialow / liczba_watkow;
        long long end_range = (i + 1) * liczba_przedzialow / liczba_watkow;

        threads.push_back(std::thread([this, start_range, end_range, i, &results]()
        {
            results[i] = oblicz_czesc(start_range, end_range);
        }));
    }

    for (auto& t : threads)  
    {
        t.join();
    }

    wynik_pi = 0;
    for (int i = 0; i < liczba_watkow; i++)  
    {
        wynik_pi += results[i];
    }

    wynik_pi *= 1.0 / liczba_przedzialow;  
    auto end = std::chrono::high_resolution_clock::now(); 
    czas_obliczen = std::chrono::duration<double>(end - start).count();  
}

double Integral::pobierz_wynik_pi()
{
    return wynik_pi;
}

double Integral::pobierz_czas_obliczen()
{
    return czas_obliczen;
}
