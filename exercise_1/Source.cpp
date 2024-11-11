#include <iostream>
using namespace std;
struct f
{
	long long NISN {};
	long score {};
	string n{};
};
string N[7] = { "Handi Ramadhan", "Rio Alfandra", "Ronaldo Valentino Uneputty", "Achmad Yaumil Fadjri R.", "Alivia Rahma Pramesti", "Ari Lutfianto", "Arief Budiman"};
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
		long long s = x[i].NISN, k{i};
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
void print_shorted_NISN(f x[])
{
	cout << "NISN		score	name\n";
	for (int i{ 0 }; i < 7; i++)
	{
		cout << x[i].NISN << "	" << x[i].score << "	"<< x[i].n << '\n';
	}
	cout << '\n';
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
int main()
{
	f A[7], B[7], C[7], D[7], E[7],	F[7];
	cout << "by NISN\n\n";
	fill(A);
	insertion_NISN(A);
	print_shorted_NISN(A);
	fill(B);
	selection_NISN(B);
	print_shorted_NISN(B);
	fill(C);
	bubble_NISN(C);
	print_shorted_NISN(C);
	cout << "___________________\n\n" << "by score\n\n";
	fill(D);
	fill(E);
	fill(F);
	insertion_score(D);
	selection_score(E);
	bubble_score(F);
	print_shorted_score(D);
	print_shorted_score(E);
	print_shorted_score(F);
	return 0;
}