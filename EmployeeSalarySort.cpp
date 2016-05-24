#include "employee.h"

void merge(vector<employee>& a, int from, int mid, int to)
{
	int n = to - from + 1;
	vector<employee>b(n);
	int i1 = from;
	int i2 = mid + 1;
	int j = 0;
	while (i1 <= mid && i2 <= to)
	{
		if (a[i1].getSalary() < a[i2].getSalary())
		{
			b[j] = a[i1];
			i1++;
		}
		else
		{
			b[j] = a[i2];
			i2++;
		}
		j++;
	}
	while (i1 <= mid)
	{
		b[j] = a[i1];
		i1++;
		j++;
	}

	while (i2 <= to)
	{
		b[j] = a[i2];
		i2++;
		j++;
	}

	for (int i = 0; i < n; i++)
		a[from + i] = b[i];
}

void  mergeSort(vector<employee> &a, int from, int to)
{
	if (from == to) return;
	int mid = (from + to) / 2;
	mergeSort(a, from, mid);
	mergeSort(a, mid + 1, to);
	merge(a, from, mid, to);
}

void print(vector<employee> a) //Prints elements of the vector.
{
	for (int i = 0; i < a.size(); i++)
		cout << i << ". Employee name: " << a[i].getName() << "\n Employee Salary: " << a[i].getSalary() << endl;
}

int main()
{
	//Creates the employee vector and initializes the first 5 elements to set values.
	vector<employee> x(5);
	x[0].setName("Duane"); x[0].setSalary(65750);
	x[1].setName("Estefania"); x[1].setSalary(68855);
	x[2].setName("Tommy"); x[2].setSalary(42755);
	x[3].setName("Jenn"); x[3].setSalary(52710);
	x[4].setName("Blaine"); x[4].setSalary(39550);
	
	salaryIncrease(x); //Calls the salary increase function to run the appropriate raise calculations.
	mergeSort(x, 0, x.size()-1); //Calls the mergeSort function with the employee vector, 0 for the cell to begin with, and x.size()-1 for the cell to end with.
	print(x); //Calls the print function

	system("PAUSE");
    return 0;
}

