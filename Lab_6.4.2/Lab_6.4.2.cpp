#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;

void change2(int* arr, int size, int j);
void suma(int* arr, int index, int i, int& S);
void create(int* arr, int size,int i)
{
	arr[i] = 200. * rand() / RAND_MAX-100;
	if (i<size-1)
	{
		create(arr, size, i + 1);
	}
}

void show(int* arr, int size,int i)
{
	cout << setw(4) << arr[i];
	if (i<size-1)
	{
		show(arr, size, i + 1);
	}
}

int search(int* arr, int size,int max,int i)
{
	if (max < arr[i])
	{
		max = arr[i];
	}
	if (i<size-1)
	{
		search(arr, size, max, i + 1);
	}
	else
	{
		return max;
	}
}


void sum(int * arr,int size,int i ,int &S,int &index,int k,int &counter)
{
		if (arr[i] > 0 && k != 0)
		{
			index = i;
			k = 0;
		}
		if (i >= 0 && k != 0)
		{
			sum(arr, size, i - 1, S, index, k,counter);
		}
		counter++;
		suma(arr, index, 0, S);
}

void suma(int * arr,int index,int i,int &S)
{
	if (i<=index)
	{
		S += arr[i];
		suma(arr,index,i+1,S);
	}
}
void change(int* arr, int size, int a, int b,int i,int &j)
{
	if (i < size - 1)
	{
		if (abs(arr[i]) <= a || abs(arr[i]) >= b)
		{
			int tmp = arr[j];
			arr[j] = arr[i];
			j++;
		}
	}
	if (i < size-1)
	{
		change(arr, size, a, b, i + 1, j);
	}
	else
	{
		change2(arr, size, j);
	}
}

void change2(int * arr,int size,int j)
{
	if (j < size)
	{
		arr[j] = 0;
		change2(arr, size,j+1);
	}
}

int main()
{
	srand((unsigned)time(NULL));

	int size, a, b, S=0,j=0, counter=0;
	cout << "size = "; cin >> size;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	int index = size - 1;
	int* arr = new int[size];

	create(arr, size,0);
	show(arr, size,0);
	int max = search(arr, size,arr[0],1);
	sum(arr, size, size, S, index,-1,counter);
	cout << endl;
	cout << "max = " << max << endl;
	cout << "S = " << S/counter << endl;
	change(arr, size, a, b, 0, j);
	show(arr, size, 0);
	cout << endl;
	delete[] arr;
	return 0;
}
