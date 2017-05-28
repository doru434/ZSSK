#include "fileReader.h"

int main()
{
	//int n;
//	bool check;
	fileReader reader;

	Matrix matrix(reader.data[0], reader.data[1], reader.tablica);
	matrix.showMatrix();
	
	//cout << endl << "Wybierz kryterium \n1.Odleglosc \n2.Czas" << endl;
	//cin >> n;

	matrix.DijkstraDistance(reader.data[2]);
	matrix.DijkstraShowDistance(reader.data[2], reader.data[3]);

	system("Pause");
	return 0;
}