#include <iostream>
#include <string>
using namespace std;
struct f
{
	long long NISN{};
	long score{};
	string n{};
};
string N[7] = { "Handi Ramadhan", "Rio Alfandra", "Ronaldo Valentino Uneputty", "Achmad Yaumil Fadjri R.", "Alivia Rahma Pramesti", "Ari Lutfianto", "Arief Budiman" };
long long NISN[] = { 9960312699, 9963959682, 9950310962, 9970272750, 9970293945, 9952382180, 9965653989 };
long score[7] = { 90, 55, 80, 60, 70, 65, 60 };
void fill(f x[])
{
	for (int i{ 0 }; i < 7; i++)
	{
		x[i].NISN = NISN[i];
		x[i].score = score[i];
		x[i].n = N[i];
	}
}
void swap(long long& x, long long& y)
{
	long long t = x;
	x = y;
	y = t;
}
void insertion_NISN(f x[])
{
	for (int i{ 1 }; i < 7; i++)
	{
		for (int j{ 1 }; x[i - j].NISN < x[i + 1 - j].NISN && j <= i; j++)
		{
			swap(x[i - j], x[i + 1 - j]);
		}
	}
}
void print_shorted_score(f x[])
{
	cout << "score	NISN		name\n";
	for (int i{ 0 }; i < 7; i++)
	{
		cout << x[i].score << "	" << x[i].NISN << "	" << x[i].n << '\n';
	}
	cout << '\n';
}
string search_NISN(f x[], long long y)
{
	int L{ 0 }, R{ 6 };
	while (L <= R)
	{
		if (x[(L + R) / 2].NISN == y)
		{
			return to_string((x[(L + R) / 2].score));
		}
		else if (y > x[(L + R) / 2].NISN)
		{
			R = (L + R) / 2 - 1;
		}
		else if (y < x[(L + R) / 2].NISN)
		{
			L = (L + R) / 2 + 1;
		}
	}
	return "not found";
}
void joko(f x[], int y)
{
	for (int i{ 0 }; i < 7; i++)
	{
		if (x[i].score == y)
		{
			x[i].n = "Joko";
		}
	}
}
int main()
{
	f A[7];
	fill(A);
	insertion_NISN(A);
	cout << "student 9950310962 score value: " << search_NISN(A, 9950310962);
	cout << '\n' << '\n';
	joko(A, 60);
	print_shorted_score(A);
	return 0;
}