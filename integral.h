#pragma once

#include <vector>
#include <chrono>

class Integral {

private:
    long long int liczba_przedzialow;  // Liczba przedzia��w (zmiana na long long int)
    int liczba_watkow;                 // Liczba w�tk�w
    double wynik_pi;                   // Wynik oblicze� liczby pi
    double czas_obliczen;              // Czas trwania oblicze�

    // Funkcja obliczaj�ca cz�� wyniku
    double calculate_partial(long long int start, long long int end);

public:
    // Konstruktor klasy
    Integral(long long int intervals, int threads);

    // Funkcja obliczaj�ca wynik ca�kowania
    void oblicz();

    // Funkcje zwracaj�ce wynik oraz czas oblicze�
    double pobierz_wynik_pi();
    double pobierz_czas_obliczen();
};
