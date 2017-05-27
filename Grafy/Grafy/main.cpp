#include "fileReader.h"

int main()
{
	bool check;
	fileReader reader;

	Matrix matrix(reader.data[0], reader.data[1], reader.tablica, 0);

	matrix.showMatrix();
	matrix.Dijkstra(reader.data[2]);
	matrix.DijkstraShow(reader.data[2]);

	system("Pause");
	return 0;
}