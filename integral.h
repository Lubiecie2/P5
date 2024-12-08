#pragma once

#include <vector>
#include <chrono>

class Integral {
private:
   
    long long liczba_przedzialow;  // Liczba przedzia³ów (zmienione na long long)
    int liczba_watkow;             // Liczba w¹tków
    double wynik_pi;               // Wynik obliczeñ liczby Pi
    double czas_obliczen;          // Czas trwania obliczeñ

    double oblicz_czesc(long long start, long long end); // Funkcja obliczaj¹ca czêœæ wyniku

public:
    
    Integral(long long intervals, int threads); // Konstruktor klasy

    void oblicz(); // Funkcja obliczaj¹ca wynik

    double pobierz_wynik_pi(); // Funkcja zwracaj¹ca wynik
    double pobierz_czas_obliczen(); // Funkcja zwracaj¹ca czas trwania obliczeñ
};