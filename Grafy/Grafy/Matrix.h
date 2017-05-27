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
	int distance_train;
	int distance_bus;
	int distance_taxi;
	int time_train;
	int time_bus;
	int time_taxi;
};

class Matrix
{
private:

	int vertices;
	int edges;
	int *d;              // Tablica kosztów dojœcia 
	long long *d2;       // Tablica kosztów dojœcia ford
	int *p;              // Tablica poprzedników
	bool minus = false;

	vector< vector<Edge> > matrix;


public:
	Matrix(int v, int e, vector<Edge> &data);

	void showMatrix();

	//void Dijkstra(int i);
	//void Dijkstra(int beginning);
	//void DijkstraShow(int beginning, int end);

};