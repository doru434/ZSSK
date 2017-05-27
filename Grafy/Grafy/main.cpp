#include "fileReader.h"

int main()
{
	int n;
	bool check;
	fileReader reader;

	Matrix matrix(reader.data[0], reader.data[1], reader.tablica, 0);
	matrix.showMatrix();
	
	//cout << endl << "Wybierz kryterium \n1.Odleglosc \n2.Czas" << endl;
	//cin >> n;

	matrix.Dijkstra(reader.data[2], 1,3);
	matrix.Dijkstra(reader.data[2], 2,3);

	system("Pause");
	return 0;
}