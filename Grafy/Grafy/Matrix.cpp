#include "Matrix.h"


Matrix::Matrix(int v, int e, vector<Edge> &data)
{
	vertices = v;
	edges = e;

	for (int i = 0; i < vertices; i++)
	{
		vector<int> row;
		for (int j = 0; j < vertices; j++)
		{
			row.push_back(0);
		}
		Dmatrix.push_back(row);
		Tmatrix.push_back(row);
	}

	for (int i = 0; i < edges; i++)
	{
		Dmatrix.at(data.at(i).beginning).at(data.at(i).end) = data.at(i).distance;
	}
}
Matrix::Matrix(int v, int e, vector<Edge> &data, int d)
{
	vertices = v;
	edges = e;

	for (int i = 0; i < vertices; i++)
	{
		vector<int> row;
		for (int j = 0; j < vertices; j++)
		{
			row.push_back(0);
		}
		Dmatrix.push_back(row);
		Tmatrix.push_back(row);
	}

	for (int i = 0; i < edges; i++)
	{
		Dmatrix.at(data.at(i).beginning).at(data.at(i).end) = data.at(i).distance;
		Dmatrix.at(data.at(i).end).at(data.at(i).beginning) = data.at(i).distance;
		Tmatrix.at(data.at(i).beginning).at(data.at(i).end) = data.at(i).time;
		Tmatrix.at(data.at(i).end).at(data.at(i).beginning) = data.at(i).time;
	}
}

void Matrix::showMatrix()
{
	cout << endl << endl << "Macierz odleglosci" << endl;
	for (int i = 0; i < Dmatrix.size(); i++)
	{
		cout << "El[" << i << "] = ";
		for (int j = 0; j < Dmatrix.at(i).size(); j++)
		{
			cout << Dmatrix.at(i).at(j) << "  ";
		}
		cout << endl;
	}

	cout << endl << endl << "Macierz czasow" << endl;
	for (int i = 0; i < Tmatrix.size(); i++)
	{
		cout << "El[" << i << "] = ";
		for (int j = 0; j < Tmatrix.at(i).size(); j++)
		{
			cout << Tmatrix.at(i).at(j) << "  ";
		}
		cout << endl;
	}
}

void Matrix::Dijkstra(int i, int n, int e)
{
	switch (n)
	{
		case 1:
			DijkstraDistance(i);
			DijkstraDShow(i,e);
			cin.ignore();
			break;
		case 2:
			DijkstraTime(i);
			DijkstraTShow(i, e);
			cin.ignore(i);
			break;
		break;
	}
}


void Matrix::DijkstraDistance(int beginning)
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

		vector<int> temp = Dmatrix.at(u);

		for (int index = 0; index < Dmatrix.size(); index++)
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
void Matrix::DijkstraDShow(int beginning, int end)
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


void Matrix::DijkstraTime(int beginning)
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

		vector<int> temp = Tmatrix.at(u);

		for (int index = 0; index < Tmatrix.size(); index++)
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

void Matrix::DijkstraTShow(int beginning, int end)
{
	cout << endl << "Najkorzystniejsza trasa ze wzgledu na czas";
	int *Stos = new int[vertices];              // Stos
	int sptr = 0;							    // WskaŸnik stosu

	cout << endl << "Start: " << beginning << "  Punkt Docelowy: " << end << endl;
	cout << endl << "TIME  " << "Path  " << endl;
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