#include "President.h"

int main()
{
	Employer* arr[3] = { new President("President"),
		                 new Worker("Worker"),
		                 new Manager("Manager") };
	for (int i = 0; i < 3; i++)
	{
		arr[i]->print();
	}
	return 0;
}