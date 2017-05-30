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

	// Tablice kosztów dojœcia 
	int *d_distance;              
	int *d_time;             
            
	// Tablice poprzedników
	int *p_distance;
	int *p_time;

	//bool minus = false;

	vector< vector<Edge> > matrix;


public:
	Matrix(int v, int e, vector<Edge> &data);

	void showMatrix();

	void DijkstraDistance(int beginning);
	void DijkstraTime(int beginning);
	void DijkstraShowDistance(int beginning, int end);
	void DijkstraShowTime(int beginning, int end);

};