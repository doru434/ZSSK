#include "fileReader.h"

int main()
{
	bool check;
	fileReader reader;

	macierzSasiedztwa macierz(reader.data[0], reader.data[1], reader.tablica);

	macierz.showMatrix();
	macierz.Dijkstra(reader.data[2]);
	macierz.DijkstraShow(reader.data[2]);

	system("Pause");
	return 0;
}