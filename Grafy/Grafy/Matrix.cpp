#include "Matrix.h"


Matrix::Matrix(int v, int e, vector<Edge> &data)
{
	vertices = v;
	edges = e;

	for (int i = 0; i < vertices; i++)
	{
		vector<Edge> row;
		Edge zero = { 0,0,0,0,0,0,0,0 };
		for (int j = 0; j < vertices; j++)
		{
			row.push_back(zero);
		}
		matrix.push_back(row);
	}

	for (int i = 0; i < edges; i++)
	{
		Edge temp;

		temp.distance_train = data.at(i).distance_train;
		temp.distance_bus = data.at(i).distance_bus;
		temp.distance_taxi = data.at(i).distance_taxi;

		temp.time_train = data.at(i).time_train;
		temp.time_bus = data.at(i).time_bus;
		temp.time_taxi = data.at(i).time_taxi;
		
		matrix.at(data.at(i).beginning).at(data.at(i).end) = temp;
	}
}


void Matrix::showMatrix()
{
	cout << endl << endl << "Macierz odleglosci" << endl;
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << "El[" << i << "] = ";
		for (int j = 0; j < matrix.at(i).size(); j++)
		{
			cout << matrix.at(i).at(j).distance_train  << "  " << matrix.at(i).at(j).distance_bus << "  " << matrix.at(i).at(j).distance_taxi << " | " << matrix.at(i).at(j).time_train << "  " << matrix.at(i).at(j).time_bus << "  " << matrix.at(i).at(j).time_taxi << "    ";
		}
		cout << endl;
	}

}
/*

void Matrix::Dijkstra(int beginning)
{
	d = new int[vertices];
	p = new int[vertices];

	// Tworzymy tablice dynamiczne

	bool *S = new bool[vertices];           // Zbior S

											// Inicjujemy tablice dynamiczne

	for (int i = 0; i < vertices; i++)
	{
		d[i] = MAXINT;
		p[i] = -1;
		S[i] = false;
	}

	d[beginning] = 0;							// Koszt dojœcia v jest zerowy
	
												// Wyznaczamy œcie¿ki

	for (int i = 0; i < vertices; i++)
	{
		Edge pw;
		int j, u, x = 0;

		// Szukamy wierzcho³ka w Q o najmniejszym koszcie d

		for (j = 0; S[j]; j++);
		for (u = j++; j < vertices; j++)
			if (!S[j] && (d[j] < d[u]))
				u = j;

		// Znaleziony wierzcho³ek przenosimy do S

		S[u] = true;

		// Modyfikujemy odpowiednio wszystkich s¹siadów u, którzy s¹ w Q

		vector<int> temp = matrix.at(u);

		for (int index = 0; index < matrix.size(); index++)
		{
			if (temp.at(index) != 0)
			{
				if (!S[index] && (d[index] > d[u] + temp.at(index)))
				{
					d[index] = d[u] + temp.at(index);
					p[index] = u;
				}
			}
		}

	}
}
void Matrix::DijkstraShow(int beginning, int end)
{
	cout << endl << "Najkorzystniejsza trasa ze wzgledu na odleglosc";
	int *Stos = new int[vertices];              // Stos
	int sptr = 0;							    // WskaŸnik stosu

	cout << endl << "Start: " << beginning << " Punkt Docelowy: " << end << endl;
	cout << endl << "DIST " << "Path  " << endl;
	//wyniki
	for (int i = 0; i < vertices; i++)
	{

		if (i == end)
		{
			// Œcie¿kê przechodzimy od koñca ku pocz¹tkowi,
			// Zapisuj¹c na stosie kolejne wierzcho³ki

			for (int j = i; j > -1; j = p[j])
				Stos[sptr++] = j;

			// Wypisujemy jej koszt

			cout << d[i] << "  | ";
			// Wyœwietlamy œcie¿kê, pobieraj¹c wierzcho³ki ze stosu

			while (sptr)
				cout << Stos[--sptr] << " ";

			cout << endl;
			break;
		}
	}
}
*/