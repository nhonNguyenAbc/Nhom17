#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define SIZE 50
struct SUCCESSOR
{
	int SUC;
	SUCCESSOR* next;
};

struct NODE
{
	int COUNT;
	SUCCESSOR* TOP;
};
int main() {
	SUCCESSOR* P;
	int QLINK[SIZE] = { 0 };
	NODE A[SIZE];
	int n, edges;
	// T1
	cout << "Nhap so dinh va so canh:\n";
	cin >> n >> edges; // Nhap so luong phan tu va so canh
	int N = n;
	for (int i = 1; i <= n; i++)
	{
		A[i].COUNT = 0;
		A[i].TOP = NULL;
	}
	// T2 + T3
	cout << "Nhap canh:\n";
	for (int i = 0; i < edges; i++)
	{
		int j, k;
		cin >> j >> k;
		A[k].COUNT++;
		P = (SUCCESSOR*)malloc(sizeof(SUCCESSOR));
		P->SUC = k;
		P->next = A[j].TOP;
		A[j].TOP = P;
	}

	// T4
	int R = 0;
	QLINK[0] = 0;
	for (int k = 1; k <= n; k++)
	{
		if (A[k].COUNT == 0)
		{
			QLINK[R] = k;
			R = k;
		}
	}

	// step 5
	int F = QLINK[0];
	while (F != 0) {
		cout << F << " ";
		N--;
		P = A[F].TOP;
		while (P != NULL) {
			A[P->SUC].COUNT--;
			if (A[P->SUC].COUNT == 0)
			{
				QLINK[R] = P->SUC;
				R = P->SUC;
			}
			P = P->next;
		}
		F = QLINK[F];
	}
	return 0;
}