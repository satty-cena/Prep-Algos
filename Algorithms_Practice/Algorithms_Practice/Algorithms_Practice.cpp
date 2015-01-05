// Algorithms_Practice.cpp : Defines the entry point for the console application.


/*Merge of two sorted arrays into a sorted array
In-place sorting*/

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <deque>
#include <map>

using namespace std;

void merge(int a[], int m, int b[], int n);
void slidingWindowMaximum(int A[], int n, int w, int B[]);
void quicksort(int a[], int p, int r);
int Partition(int a[], int p, int r);
void removeDuplicates(char *str);
bool isPalindrome(char * str);
char *reverseString(char *str);
bool findpair(int arr[], int m, int k);
int findRepeatedNumber(int arr[], int m);
void twoArrayPairs(int a[], int b[], int m, int n);


int main() {

	/*int a[] = { 7, 18, 25, 30, 0, 0, 0, 0, 0 };  ///Test case for merge
	int b[] = { 5, 15, 45, 60, 70 };

	int a_size = sizeof(a) / sizeof(a[0]);
	int b_size = sizeof(b) / sizeof(b[0]);

	merge(a, a_size - b_size, b, b_size);

	for (int i = 0; i<a_size; i++)
	{
		cout << a[i] << " ";
	}*/

	/*int a[] = {5,8,7,2,6,9};  ///For sliding window problem
	int b[] = { 0, 0, 0, 0 };
	int w = 3;
	int n = sizeof(a) / sizeof(a[0]);
	slidingWindowMaximum(a, n, w, b);

	for (int i = 0; i < sizeof(b)/sizeof(b[0]); i++)
	{
		cout << b[i] << " ";
	}*/


	/*int a[] = { 2, 8, 7, 1, 3, 5, 6, 4};
	int n = sizeof(a) / sizeof(a[0]);
	quicksort(a, 0, n-1);

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
*/
	/*char str[] = "haha happy";
	removeDuplicates(str);
	
	for (int i = 0; i < strlen(str); i++)
	{
		cout << str[i];
	}*/


	/*char str[] = "banana";
	cout << isPalindrome(str) << endl;*/

	/*char  str[] = "i am dude";
	char * ret = reverseString(str);*/

	/*int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int m = sizeof(arr) / sizeof(arr[0]);
	int sum = 81;
	cout << findpair(arr, m, sum);*/

	/*int arr[] = { 1, 2, 3, 4, 4 };
	cout << findRepeatedNumber(arr, 5) << endl;*/

	int a[] = { 2,5,15,30 };
	int b[] = { 3, 8, 2 , 10, 15, 25};
	int m = sizeof(a) / sizeof(a[0]);
	int n = sizeof(b) / sizeof(b[0]);

	twoArrayPairs(a, b, m,n);

	getchar();
	return 0;
}

void merge(int a[], int m, int b[], int n)
{
	int i = 1;
	int j = n - 1;
	int k = m - 1;

	while (k>=0 && j>=0)
	{
		if (a[k] >= b[j])
		{
			a[m + n - i] = a[k];
			--k; ++i;
		}
		else if (a[k]<b[j])
		{
			a[m + n - i] = b[j];
			--j; ++i;
		}
	}

	//Merge remaining elements from one the sub arrays.

	if (k >= 0)
	{
		for (int z = k; z>=0; z--)
		{
			a[m + n - i] = a[z];
			++i;
		}
	}

	else if (j >= 0)
	{
		for (int z = j; z>=0; z--)
		{
			a[m + n - i] = b[z];
			++i;
		}
	}
}

void slidingWindowMaximum(int A[], int n, int w, int B[])
{
	std::deque<int> Q;

	for (int i = 0; i < w; i++)
	{
		while (!Q.empty() && A[i]>=A[Q.back()])
		{
			Q.pop_back();
		}
		Q.push_back(i);
	}

	for (int i = w; i < n; i++)
	{
		B[i - w] = A[Q.front()];
		while (!Q.empty() && A[i] >= A[Q.back()])
		{
			Q.pop_back();
		}

		while (!Q.empty() && Q.front() <= i - w)
		{
			Q.pop_front();
		}

		Q.push_back(i);
	}

	B[n - w] = A[Q.front()];
}


void Swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void quicksort(int a[], int p, int r)
{
	if (p < r)
	{
		int q = Partition(a, p, r);

		/*for (int i = 0; i <= r; i++)
		{
			cout << a[i] << " ";
		}*/
		quicksort(a, p, q-1);
		quicksort(a, q+1, r);
	}
}

int Partition(int a[], int p, int r)
{
	int x = a[r];
	int i = p - 1;
	for (int j = 0; j <= r - 1; j++)
	{
		if (a[j] <= x)
		{
			i = i + 1;
			Swap(&a[j], &a[i]);
		}
	}

	Swap(&a[i + 1], &a[r]);
	return i + 1;
}

void removeDuplicates(char *str)
{
	bool hash[256] = { 0 };
	char temp;
	int str_ind = 0, res_ind = 0;

	while (*(str + str_ind))
	{
		temp = *(str + str_ind);
		if (hash[temp] == 0)
		{
			hash[temp] = 1;
			*(str + res_ind) = *(str + str_ind);
			res_ind++;
		}
		str_ind++;
	}
	*(str + res_ind) = '\0';
}


bool isPalindrome(char * str)
{
	for (int i = 0; i < strlen(str) / 2; i++)
	{
		if (str[i] != str[strlen(str) - i - 1])
			return false;
	}
	return true;
}

char *reverseString(char *str)
{
	int last = strlen(str) - 1;
	int first = 0;
	while (first < last)
	{
		str[first] ^= str[last];
		str[last] ^= str[first];
		str[first] ^= str[last];
		++first;
		--last;
	}
	return str;
}

void reverseWord(char *str)
{

}

bool findpair(int arr[], int m, int k)
{
	bool flag = false;
	int hash[1000];
	for (int i = 0; i < m; i++)
	{
		hash[arr[i]] = i;
	}

	for (int i = 0; i < m; i++)
	{
		if (hash[k - arr[i]] != i)
		{
			flag = true;
		}
	}
	return flag;
}

int findRepeatedNumber(int arr[], int m)
{
	int hash[1000] = { 0 };
	int extra;
	int subsum = 0;
	for (int i = 0; i < m; i++)
	{
		if (hash[arr[i]] == 0)
			hash[arr[i]] = i;
		else
		{
			hash[arr[i]] = i;
			extra = arr[i];
		}
	}

	for (int i = 0; i < m; i++)
	{
		subsum += arr[i];
	}

	int sum = (m * (m + 1)) / 2;
	int missednum = sum - subsum + extra;

	return extra;
}


void twoArrayPairs(int a[], int b[], int m, int n)
{
	int i = 0, j = 1, r;

	if (n < m || n==m)
	{
		m = n - 1;
	}

	r = j;
	std::multimap <int, int> pair;
	while (i < m && j < n)
	{
		if (a[i]>b[j])
		{
			pair.insert({ i, j });
		}

		if (j == n-1)
		{
			i++;
			j = r + 1;
			r++;
		}
		else
		   j++;
	}

	int size = pair.size();
	for (const auto &p : pair)
	{
		cout << p.first << " " << p.second << endl;
	}

}



