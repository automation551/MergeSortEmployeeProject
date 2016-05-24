#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Object class that holds an employee's name and salary
class employee
{
public:
	employee();
	employee(string employeeName, double initialSalary);
	void setName(string newName);
	void setSalary(double newSalary);
	void raiseSalary(double percent);
	void print();
	string getName() const;
	double getSalary() const;
	double findAverage(double xArray[], int size);

private:
	string name;
	double salary;
};

/*
employee() -- Default constructor, initializes private members.
employee(string, double) -- Constructor with parameters, sets values of private members.
setName -- Sets the value of private member name.
setSalary -- Sets the value of private member salary.
raiseSalary -- Sets the value of salary to a new  value based on a given percentage.
print -- Prints private members.
getName -- Returns private member name.
getSalary -- Returns private member salary.
findAverage -- Finds the average of values in an array.
*/

inline employee::employee() { name = "None"; salary = 0.0; }
inline employee::employee(string employeeName, double initialSalary) { name = employeeName; salary = initialSalary; }
inline void employee::setName(string newName) { name = newName; }
inline void employee::setSalary(double newSalary) { salary = newSalary; }
inline void employee::raiseSalary(double percent) { salary = salary * (1 + percent / 100); }
inline void employee::print() { cout << "Employee Name: " << name << endl; cout << "Salary: " << salary << endl; }
inline string employee::getName()const { return name; }
inline double employee::getSalary() const { return salary; }
inline double employee::findAverage(double xArray[], int size) //#2-A
{
	int i = 0;
	double average = 0.0; double sum = 0.0;
	for (i = 0; i < size; i++)
		sum += xArray[i];
	average = sum / size;
	return average;
}


//Determines pay increases based on current income. (#1-B)
inline void salaryIncrease(vector<employee> &myEmployee)
{

	for (int i = 0; i < myEmployee.size(); i++)
	{
		double xSalary = myEmployee[i].getSalary();
		if (myEmployee[i].getSalary() < 40000)
		{
			xSalary = xSalary + (xSalary * 0.20);
			myEmployee[i].setSalary(xSalary);
		}
		else if ((myEmployee[i].getSalary() >= 40000) && (myEmployee[i].getSalary() < 60000))
		{
			xSalary = xSalary + (xSalary * 0.10);
			myEmployee[i].setSalary(xSalary);
		}
		else
		{
			xSalary = xSalary + (xSalary * 0.05);
			myEmployee[i].setSalary(xSalary);
		}
	}
}

//Determines which index in the vector holds the highest paid employee (#1-C)
inline int highestPaidIndex(vector<employee> x)
{
	int highest = 0;
	employee lEmp = x[0];

	for (int i = 0; i < x.size(); i++)
	{
		if (lEmp.getSalary() < x[i].getSalary())
		{
			lEmp = x[i];
			highest = i;
		}
	}
	return highest;
}

//Determines employees that earn more than $70k and stores them in a new vector. (#1-D)
inline employee empOverSeventy(vector<employee> y)
{
	vector<employee> z(y.size());
	int count = 0;

	for (int i = 0; i < y.size(); i++)
	{
		if (y[i].getSalary() > 70000)
		{
			z[i] = y[i];
			count++;
		}
	}
	return z[count];
}

#endif