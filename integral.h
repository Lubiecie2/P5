#pragma once

#include <vector>
#include <chrono>

class Integral {

private:
    long long int liczba_przedzialow;  // Liczba przedzia³ów (zmiana na long long int)
    int liczba_watkow;                 // Liczba w¹tków
    double wynik_pi;                   // Wynik obliczeñ liczby pi
    double czas_obliczen;              // Czas trwania obliczeñ

    // Funkcja obliczaj¹ca czêœæ wyniku
    double calculate_partial(long long int start, long long int end);

public:
    // Konstruktor klasy
    Integral(long long int intervals, int threads);

    // Funkcja obliczaj¹ca wynik ca³kowania
    void oblicz();

    // Funkcje zwracaj¹ce wynik oraz czas obliczeñ
    double pobierz_wynik_pi();
    double pobierz_czas_obliczen();
};
