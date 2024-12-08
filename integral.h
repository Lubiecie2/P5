#pragma once

#include <vector>
#include <chrono>

class Integral {

private:
	int num_intervals;  // <--- Liczba przydzia��w
	int num_threads;   // <--- Liczba w�tk�w
	double pi_result; // <--- Wynik oblicze� liczby pi
	double duration; // <--- Czas trwania oblicze�

	double calculatre_partial(int start, int end); // <--- Funkcja obliczaj�ca cz�� wyniku

public:
	Integral(int intervals, int threads); // <--- Konstruktor klasy 

	void calculate(); // <--- Funkcja obliczaj�ca wynik

	double get_pi(); // <--- Funkcja zwracaj�ca wynik
	double get_duration(); // <--- Funkcja zwracaj�ca czas trwania oblicze�
};