
#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> beolvasas();
vector<int> feldolgozas(vector<vector<int>>);
int maxfokszamu(vector<int>&);
int egyes_fokszamuak_szama(vector<int>&);
void kiiras(vector<int>);



vector<vector<int>> beolvasas() {
	int N;
	int M;

	cin >> N; // az elsõ whitespace-ig olvas!
	cin >> M;
	vector<vector<int>> result(M);
	for (size_t i = 0; i < M; i++)
	{
		vector<int> sor(2);
		cin >> sor[0] >> sor[1];
		result[i] = sor;
	}
	return result;
}

vector<int> feldolgozas(vector<vector<int>> graf) {
	int N = graf[0][0];
	int M = graf[0][1];
	vector<int> fokszam(N+1);

	for (size_t i = 1; i < graf.size(); i++)
	{
		fokszam[graf[i][0]]++;
		fokszam[graf[i][1]]++;
	}

	int db = egyes_fokszamuak_szama(fokszam);
	int max = maxfokszamu(fokszam);

	return vector<int> { db, max };
}

int maxfokszamu(vector<int>& fokszam) {
	int maxi = 1;
	for (size_t i = 2; i < fokszam.size(); i++)
	{
		if (fokszam[maxi]<fokszam[i])
		{
			maxi = i;
		}
	}
	return maxi;
}

int egyes_fokszamuak_szama(vector<int>& fokszam) {
	int db = 0;
	for (int e : fokszam)
	{
		if (e == 1)
		{
			db++;
		}
	}
	return db;
}


void kiiras(vector<int> mo) {
	cout << mo[0] << " " << mo[1] << endl;
}


int main()
{
	vector<vector<int>> input = beolvasas();
	vector<int> output = feldolgozas(input);
	kiiras(output);
	//kiiras(feldolgozas(beolvasas()));
}


/** /

5 7
0 1
1 4
3 1
3 5
2 0
2 3
1 2

/**/