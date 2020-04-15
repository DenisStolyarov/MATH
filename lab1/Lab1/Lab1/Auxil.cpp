#include "pch.h"
#include "Auxil.h"

//RAND_MAX = 32767
namespace auxil
{
	void start()// старт  генератора сл. чисел 
	{
		/*
		ƒл€ того, чтобы генерировать случайные числа, функци€ srand обычно инициализируетс€ некоторыми различными значени€,
		например, такие значени€ генерируютс€ функцией time. «начение, возвращенное функцией time (объ€влена в заголовке <ctime>)
		отличаетс€ каждую секунду, что дает возможность получать совершенно случайные последовательности чисел, 
		при каждом новом вызове функции rand.
		*/
		srand((unsigned)time(NULL)); // выполн€ет инициализацию генератора случайных чисел rand
	}

	double dget(double rmin, double rmax)// получить случайное число
	{
		return (double)rand() / RAND_MAX * (rmax - rmin) + rmin;
	}

	int iget(int rmin, int rmax)// получить случайное число
  
	{
		return (int)dget((double)rmin, (double)rmax);
	}
}