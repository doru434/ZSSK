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

struct Edge {
	int beginning;
	int end;
	int distance;
	int time;
};

class Matrix
{
private:

	int vertices;
	int edges;
	int *d;              // Tablica koszt�w doj�cia 
	long long *d2;       // Tablica koszt�w doj�cia ford
	int *p;              // Tablica poprzednik�w
	bool minus = false;

	vector< vector<int> > Dmatrix;
	vector< vector<int> > Tmatrix;

public:
	Matrix(int v, int e, vector<Edge> &data);
	Matrix(int v, int e, vector<Edge> &data, int d);
	void showMatrix();

	void Dijkstra(int i, int n, int e);
	void DijkstraDistance(int beginning);
	void DijkstraDShow(int beginning, int end);
	void DijkstraTime(int beginning);
	void DijkstraTShow(int beginning, int end);
};