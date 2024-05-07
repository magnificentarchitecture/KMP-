#include <iostream>
using namespace std;
void get_next(string& T, int next[], int len_T)
{
	next[0] = 0;
	int i = -1;
	int j = 0;
	while (j < len_T)
	{
		if (i == -1 || T[i] == T[j])
		{
			j++;
			i++;
			next[j] = i + 1;
		}
		else {
			i = next[i] - 1;

		}
	}
}
void show_next(int nextval[], int len)
{
	for (int i = 0; i < len; i++)
		cout << nextval[i] << " ";
}
void get_nextval(string& T, int nextval[], int len_T)
{
	nextval[0] = 0;
	int j = -1;
	int i = 0;
	while (i < len_T)
	{
		if (j == -1 || T[i] == T[j])
		{
			i++;
			j++;
			if (T[i] == T[j]) nextval[i] = nextval[j];
			else nextval[i] = j + 1;
		}
		else {
			j = nextval[j] - 1;
		}
	}
}
int index(int i, int next[], string s, string T, int len_T, int len_s)
{
	int j = -1;
	i--;
	while (j < len_T && i < len_s)
	{
		if (j == -1 || s[i] == T[j])
		{
			i++;
			j++;
		}
		else {
			j = next[j] - 1;
		}
	}

	return j == len_T ? i - len_T + 1 : 0;
}
int main()
{
	string s;
	string T;//Ä£°æ
	cin >> s;
	cin >> T;
	int len_T = T.size();
	int len_s = s.size();
	int* next = new int[len_T + 1];
	get_nextval(T, next, len_T);
	//show_next(next, len_T);
	cout << index(0, next, s, T, len_T, len_s) << endl;
}