#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm> 
using namespace std;

const int MAXINT = 99999;

struct Krawedz {
	int elPoczatkowy;
	int elDocelowy;
	int	waga;
};

class macierzSasiedztwa
{
private:

	int wierzcholki;
	int krawedzie;
	int *d;              // Tablica kosztów dojœcia 
	long long *d2;       // Tablica kosztów dojœcia ford
	int *p;              // Tablica poprzedników

	vector< vector<int> > macierz;

public:
	macierzSasiedztwa(int wie, int kra, vector<Krawedz> &dane);

	void showMatrix();
	void Dijkstra(int startowy);
	void DijkstraShow(int startowy);
};

