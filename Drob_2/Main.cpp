#include "Drob.h";


int main()
{
	short act;
	Drob n1, n2, n3;
	do
	{
		do
		{
			cout << "select option:\n";
			cout << "1 - Enter numbers;\n";
			cout << "2 - Sum numbers;\n";
			cout << "3 - Razn numbers;\n";
			cout << "4 - Production numbers;\n";
			cout << "5 - Divide by;\n";
			cout << "6 - Increment;\n";
			cout << "7 - Decrement;\n";
			cout << "0 - Exit.\n";
			cin >> act;
		} while (act < 0 || act>7);
		switch (act)
		{
		case 1:
		{
			cout << "Number 1:\n";
			n1.Set();
			cout << "Number 2:\n";
			n2.Set();
			break;
		}
		case 2:
		{
			//n1.Sum(n2);
			(n1 + n2).Print();
			break;
		}
		case 3:
		{
			//n1.Razn(n2);
			(n1 - n2).Print();
			break;
		}
		case 4:
		{
			//n1.Prod(n2);
			(n1 * n2).Print();
			break;
		}
		case 5:
		{
			//n1.Div(n2);
			(n1 / n2).Print();
			break;
		}
		case 6:
		{
			n1++.Print();
			++n1;
			n1.Print();
			break;
		}
		case 7:
		{
			n2--.Print();
			--n2;
			n2.Print();
			break;
		}
		default:
			break;
		}
	} while (act != 0);
}