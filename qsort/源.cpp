#include <iostream>

using namespace std;

int partion(int *data ,int low,int high)
{
	int parNum = data[low];
	while (low<high)
	{
		while (data[high] >= parNum && low<high)
		{
			high--;
		}
		if (low < high && data[high]<parNum)
		{
			data[low] = data[high];
			low++;
		}
		while (data[low] <= parNum && low < high)
		{
			low++;
		}
		if (low < high && data[low]>parNum)
		{
			data[high] = data[low];
			high--;
		}
	}
	data[low] = parNum;
	return low;
}
 
void QSort(int *data,int low, int high)
{
	if (low < high)
	{
		int par = partion(data,low,high);
		QSort(data,low,par - 1);
		QSort(data, par + 1, high);
	}
}
int main()
{
	int data[10] = { 11,2,1,3,5,6,7,8,9,10 };
	QSort(data,0,9);
	for (int i = 0; i < 10; i++)
	{
		cout << data[i] << " ";
	}

	system("pause");
	return 0;
}