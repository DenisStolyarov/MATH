#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <locale>
#include "Levenshtein.h"
using namespace std;
#define _rand(min, max) ( rand() % ((max) - (min) + 1) + (min) )

#define SIZE_1 12
#define SIZE_2 12

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	char abc[25]; // алфавит
	char s1[SIZE_1];
	char s2[SIZE_2];

	// заполняем массив
	for (int i = 97, n = 0; i <= 122; ++i, ++n)
	{
		abc[n] = (char)i; 
	}
	cout << "S1 = ";
	for (int i = 0; i < SIZE_1 + 1; i++)
	{
		s1[i] = abc[_rand(0, 25)];
		if (i % 50 == 0)
			cout << "\n";
		cout << s1[i];
	}

	cout <<"\nS2 =";
	for (int i = 0; i < SIZE_2 + 1; i++)
	{
		s2[i] = abc[_rand(0, 25)];
		if (i% 50 == 0)
			cout << "\n";
		cout << s2[i];
	}
	cout << "\n";
	
	clock_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
	int lx = sizeof(s1) ;
	int ly = sizeof(s2) ;


	int S1_size[]{ SIZE_1 / 12,SIZE_1 / 10,SIZE_1 / 8,SIZE_1 / 6,SIZE_1 /4,SIZE_1 /2,SIZE_1 };
	int S2_size[]{ SIZE_2 / 12,SIZE_2 / 10,SIZE_2 / 8,SIZE_2 / 6,SIZE_2 /4,SIZE_2 /2,SIZE_2 };
	

	std::cout << "\n\n-- расстояние Левенштейна -----";
	std::cout << "\n\n--длина --- рекурсия -- дин.програм. ---\n";

	for (int i = 0; i < min(lx, ly); i++)
	{
		t1 = clock();
		levenshtein_r(S1_size[i], s1 , S2_size[i], s2);
		t2 = clock();

		t3 = clock();
		levenshtein(S1_size[i], s1, S2_size[i], s2);
		t4 = clock();
		cout << right << setw(2) << S1_size[i] << "/" << setw(2) << S2_size[i]
			<< "        " << left << setw(10) << (t2 - t1)
			<< "   " << setw(10) << (t4 - t3) << endl;
	}
	system("pause");
	return 0;
}


