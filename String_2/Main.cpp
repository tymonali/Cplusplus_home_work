#include"String.h"

int main()
{
	String str;
	cout << "Without param.\n" << strlen(str.Get()) << "\n";
	String str1(10);
	cout << "With length param.\n" << strlen(str1.Get()) << "\n";
	String str2("qwerty");
	cout << "With string param.\n" << str2.Get() << "\n";
	str.Set();
	cout << "Result of the set string:\n";
	str.Show();
	cout << str('5') << "\n";
	cout << str[6] << "\n";
	--str;
	str.Show();
	++str;
	str.Show();
}