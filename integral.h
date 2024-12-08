#pragma once

#include <vector>
#include <chrono>

class Integral {

private:
	int num_intervals;  // <--- Liczba przydzia³ów
	int num_threads;   // <--- Liczba w¹tków
	double pi_result; // <--- Wynik obliczeñ liczby pi
	double duration; // <--- Czas trwania obliczeñ

	double calculatre_partial(int start, int end); // <--- Funkcja obliczaj¹ca czêœæ wyniku

public:
	Integral(int intervals, int threads); // <--- Konstruktor klasy 

	void calculate(); // <--- Funkcja obliczaj¹ca wynik

	double get_pi(); // <--- Funkcja zwracaj¹ca wynik
	double get_duration(); // <--- Funkcja zwracaj¹ca czas trwania obliczeñ
};