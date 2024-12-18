/// @file Integral.h
/// @brief Deklaracja klasy Integral do calkowania numerycznego w celu obliczenia wartosci liczby pi.

#pragma once

#include <vector>
#include <chrono>

/// @class Integral
/// @brief Klasa do obliczania przyblizonej wartosci liczby pi za pomoca calkowania numerycznego.
class Integral {

private:
    /// @brief Liczba przedzialow uzywana do calkowania numerycznego.
    long long int liczba_przedzialow;

    /// @brief Liczba watkow uzywana do obliczen rownoleglych.
    int liczba_watkow;

    /// @brief Wynik obliczen liczby pi.
    double wynik_pi;

    /// @brief Czas trwania obliczen.
    double czas_obliczen;

    /// @brief Oblicza czesc wyniku calki dla podanego zakresu przedzialow.
    /// @param start Indeks poczatkowego przedzialu.
    /// @param end Indeks koncowego przedzialu.
    /// @return Czesc wyniku calki.
    double calculate_partial(long long int start, long long int end);

public:
    /// @brief Konstruktor klasy Integral.
    /// @param intervals Liczba przedzialow do calkowania.
    /// @param threads Liczba watkow uzywana do obliczen.
    Integral(long long int intervals, int threads);

    /// @brief Funkcja obliczajaca wynik calkowania.
    void oblicz();

    /// @brief Zwraca wynik obliczen liczby pi.
    /// @return Wynik liczby pi.
    double pobierz_wynik_pi();

    /// @brief Zwraca czas trwania obliczen.
    /// @return Czas trwania obliczen.
    double pobierz_czas_obliczen();
};
