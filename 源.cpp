#include <iostream>
using namespace std;
void get_next(string& T, int next[],int len_T)
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
			next[j] = i+1;
		}
		else {
			i = next[i] - 1;

		}
    }
}
void show_next(int next[], int len)
{
	for (int i = 0; i < len; i++)
		cout << next[i] << " ";
}
int index(int i, int next[], string s, string T, int len_T, int len_s)
{
	int j = -1;
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
	int* next = new int[len_T+1];
	get_next(T, next, len_T);
		//show_next(next, len_T);
	cout << index(0, next, s, T, len_T, len_s) << endl;
}