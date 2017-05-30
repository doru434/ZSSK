#include "fileReader.h"

int main()
{
	fileReader reader;

	Matrix matrix(reader.data[0], reader.data[1], reader.tablica);
	matrix.showMatrix();
	
	matrix.DijkstraDistance(reader.data[2]);
	matrix.DijkstraTime(reader.data[2]);
	matrix.DijkstraShowDistance(reader.data[2], reader.data[3]);
	matrix.DijkstraShowTime(reader.data[2], reader.data[3]);

	system("Pause");
	return 0;
}