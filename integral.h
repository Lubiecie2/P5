#pragma once

#include <vector>
#include <chrono>

class Integral {
private:
   
    long long liczba_przedzialow;  // Liczba przedzia��w (zmienione na long long)
    int liczba_watkow;             // Liczba w�tk�w
    double wynik_pi;               // Wynik oblicze� liczby Pi
    double czas_obliczen;          // Czas trwania oblicze�

    double oblicz_czesc(long long start, long long end); // Funkcja obliczaj�ca cz�� wyniku

public:
    
    Integral(long long intervals, int threads); // Konstruktor klasy

    void oblicz(); // Funkcja obliczaj�ca wynik

    double pobierz_wynik_pi(); // Funkcja zwracaj�ca wynik
    double pobierz_czas_obliczen(); // Funkcja zwracaj�ca czas trwania oblicze�
};