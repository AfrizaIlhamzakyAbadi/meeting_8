#include <cassert>
#include <iostream>
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
void selection_NISN(f x[])
{
	for (int i{ 0 }; i < 6; i++)
	{
		long long s = x[i].NISN, k{ i };
		for (int j{ 1 }; i + j < 7; j++)
		{
			if (s < x[i + j].NISN)
			{
				s = x[i + j].NISN;
				k = i + j;
			}
		}
		swap(x[i], x[k]);
	}
}
void bubble_NISN(f x[])
{
	for (int i{ 0 }; i < 6; i++)
	{
		for (int j{ 0 }; j < 7; j++)
		{
			if (x[j].NISN < x[j + 1].NISN)
			{
				swap(x[j], x[j + 1]);
			}
		}
	}
}
void insertion_score(f x[])
{
	for (int i{ 1 }; i < 7; i++)
	{
		for (int j{ 1 }; x[i - j].score < x[i + 1 - j].score && j <= i; j++)
		{
			swap(x[i - j], x[i + 1 - j]);
		}
	}
}
void selection_score(f x[])
{
	for (int i{ 0 }; i < 6; i++)
	{
		long long s = x[i].score, k{ i };
		for (int j{ 1 }; i + j < 7; j++)
		{
			if (s < x[i + j].score)
			{
				s = x[i + j].score;
				k = i + j;
			}
		}
		swap(x[i], x[k]);
	}
}
void bubble_score(f x[])
{
	for (int i{ 0 }; i < 6; i++)
	{
		for (int j{ 0 }; j < 7; j++)
		{
			if (x[j].score < x[j + 1].score)
			{
				swap(x[j], x[j + 1]);
			}
		}
	}
}
int main()
{
	f nisn[7];
	nisn[0].NISN = 9970293945;
	nisn[1].NISN = 9970272750;
	nisn[2].NISN = 9965653989;
	nisn[3].NISN = 9963959682;
	nisn[4].NISN = 9960312699;
	nisn[5].NISN = 9952382180;
	nisn[6].NISN = 9950310962;
	nisn[0].score = 70;
	nisn[1].score = 60;
	nisn[2].score = 60;
	nisn[3].score = 55;
	nisn[4].score = 90;
	nisn[5].score = 65;
	nisn[6].score = 80;
	nisn[0].n = "Alivia Rahma Pramesti";
	nisn[1].n = "Achmad Yaumil Fadjri R.";
	nisn[2].n = "Arief Budiman";
	nisn[3].n = "Rio Alfandra";
	nisn[4].n = "Handi Ramadhan";
	nisn[5].n = "Ari Lutfianto";
	nisn[6].n = "Ronaldo Valentino Uneputty";
	f nilai[7];
	nilai[0].score = 90;
	nilai[1].score = 80;
	nilai[2].score = 70;
	nilai[3].score = 65;
	nilai[4].score = 60;
	nilai[5].score = 60;
	nilai[6].score = 55;
	nilai[0].NISN = 9960312699;
	nilai[1].NISN = 9950310962;
	nilai[2].NISN = 9970293945;
	nilai[3].NISN = 9952382180;
	nilai[4].NISN = 9970272750;
	nilai[5].NISN = 9965653989;
	nilai[6].NISN = 9963959682;
	nilai[0].n = "Handi Ramadhan";
	nilai[1].n = "Ronaldo Valentino Uneputty";
	nilai[2].n = "Alivia Rahma Pramesti";
	nilai[3].n = "Ari Lutfianto";
	nilai[4].n = "Achmad Yaumil Fadjri R.";
	nilai[5].n = "Arief Budiman";
	nilai[6].n = "Rio Alfandra";
	f A[7], B[7], C[7], D[7], E[7], F[7];
	fill(A);
	fill(B);
	fill(C);
	fill(D);
	fill(E);
	fill(F);
	insertion_NISN(A);
	selection_NISN(B);
	bubble_NISN(C);
	insertion_score(D);
	selection_score(E);
	bubble_score(F);
#ifdef NDEBUG
	cerr << "Tests run with NDEBUG defined (asserts compiled out)";
	abort();
#endif
	for (int i{ 0 }; i < 7; i++)
	{
		assert(A[i].NISN = nisn[i].NISN);
		assert(B[i].NISN = nisn[i].NISN);
		assert(C[i].NISN = nisn[i].NISN);
		assert(A[i].score = nisn[i].score);
		assert(B[i].score = nisn[i].score);
		assert(C[i].score = nisn[i].score);
		assert(D[i].NISN = nilai[i].NISN);
		assert(E[i].NISN = nilai[i].NISN);
		assert(F[i].NISN = nilai[i].NISN);
		assert(D[i].score = nilai[i].score);
		assert(E[i].score = nilai[i].score);
		assert(F[i].score = nilai[i].score);
		if (A[i].n == nisn[i].n)
		{
		}
		else
		{
			cout << "function insertion_NISN doesn't give the right struct name for index [" << i << "].";
			abort();
		}
		if (B[i].n == nisn[i].n)
		{
		}
		else
		{
			cout << "function seection_NISN doesn't give the right struct name for index [" << i << "].";
			abort();
		}
		if (C[i].n == nisn[i].n)
		{
		}
		else
		{
			cout << "function bubble_NISN doesn't give the right struct name for index [" << i << "].";
			abort();
		}
		if (D[i].n == nilai[i].n)
		{
		}
		else
		{
			cout << "function insertion_score doesn't give the right struct name for index [" << i << "].";
			abort();
		}
		if(E[i].n == nilai[i].n)
		{
		}
		else
		{
			cout << "function selection_score doesn't give the right struct name for index [" << i << "].";
			abort();
		}
		if(F[i].n == nilai[i].n)
		{
		}
		else
		{
			cout << "function bubble_score doesn't give the right struct name for index [" << i << "].";
			abort();
		}
	}
	cout << "All tests succeeded.";
	return 0;
}
