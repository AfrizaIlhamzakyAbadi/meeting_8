#include <cassert>
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
f A[7];
void test(f x[], int y)
{
#ifdef NDEBUG
	cerr << "Tests run with NDEBUG defined (asserts compiled out)";
	abort();
#endif
	assert(search_NISN(A, 9950310962) == "80");
	for (int l{ 0 }; l < 7; l++)
	{
		if (x[l].score == y)
		{
			assert(x[l].n == "Joko");
		}
	}
	cout << "all test succeeded";
}
int main()
{
	fill(A);
	insertion_NISN(A);
	joko(A, 60);
	test(A, 60);
	return 0;
}