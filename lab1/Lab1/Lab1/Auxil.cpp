#include "pch.h"
#include "Auxil.h"

//RAND_MAX = 32767
namespace auxil
{
	void start()// �����  ���������� ��. ����� 
	{
		/*
		��� ����, ����� ������������ ��������� �����, ������� srand ������ ���������������� ���������� ���������� ��������,
		��������, ����� �������� ������������ �������� time. ��������, ������������ �������� time (��������� � ��������� <ctime>)
		���������� ������ �������, ��� ���� ����������� �������� ���������� ��������� ������������������ �����, 
		��� ������ ����� ������ ������� rand.
		*/
		srand((unsigned)time(NULL)); // ��������� ������������� ���������� ��������� ����� rand
	}

	double dget(double rmin, double rmax)// �������� ��������� �����
	{
		return (double)rand() / RAND_MAX * (rmax - rmin) + rmin;
	}

	int iget(int rmin, int rmax)// �������� ��������� �����
  
	{
		return (int)dget((double)rmin, (double)rmax);
	}
}