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


void Matrix::DijkstraDistance(int beginning)
{
	// Tworzymy tablice dynamiczne

	d_distance = new int[vertices];

	p_distance= new int[vertices];

	// Zbior S
	bool *S_distance = new bool[vertices];         
			

	// Inicjujemy tablice dynamiczne

	for (int i = 0; i < vertices; i++)
	{
		d_distance[i] = MAXINT;
		p_distance[i] = -1;

		S_distance[i] = false;
	}
	// Koszty dojœcia v sa zerowe
						
	d_distance[beginning] = 0;

	// Wyznaczamy œcie¿ki

	for (int i = 0; i < vertices; i++)
	{
		//Edge pw;
		int j, u, x = 0;

		// Szukamy wierzcho³ka w Q o najmniejszym koszcie d

		for (j = 0; S_distance[j]; j++);
		for (u = j++; j < vertices; j++)
			if (!S_distance[j] && (d_distance[j] < d_distance[u]))
				u = j;

		// Znaleziony wierzcho³ek przenosimy do S

		S_distance[u] = true;

		// Modyfikujemy odpowiednio wszystkich s¹siadów u, którzy s¹ w Q

		vector<Edge> temp = matrix.at(u);

		for (int index = 0; index < matrix.size(); index++)
		{
			if (temp.at(index).distance_bus != 0 && temp.at(index).distance_taxi != 0  && temp.at(index).distance_train != 0)
			{
				if (temp.at(index).distance_bus < temp.at(index).distance_taxi)
				{
					if (temp.at(index).distance_bus < temp.at(index).distance_train)
					{
						if (!S_distance[index] && (d_distance[index] > d_distance[u] + temp.at(index).distance_bus))
						{
							d_distance[index] = d_distance[u] + temp.at(index).distance_bus;
							p_distance[index] = u;
						}
					}
					else
					{
						if (!S_distance[index] && (d_distance[index] > d_distance[u] + temp.at(index).distance_train))
						{
							d_distance[index] = d_distance[u] + temp.at(index).distance_train;
							p_distance[index] = u;
						}
					}
				}
				else
				{
					if (temp.at(index).distance_taxi < temp.at(index).distance_train)
					{
						if (!S_distance[index] && (d_distance[index] > d_distance[u] + temp.at(index).distance_taxi))
						{
							d_distance[index] = d_distance[u] + temp.at(index).distance_taxi;
							p_distance[index] = u;
						}
					}
					else
					{
						if (!S_distance[index] && (d_distance[index] > d_distance[u] + temp.at(index).distance_train))
						{
							d_distance[index] = d_distance[u] + temp.at(index).distance_train;
							p_distance[index] = u;
						}
					}
				}
			}
			else if (temp.at(index).distance_bus != 0 && temp.at(index).distance_taxi != 0 )
			{
				if (temp.at(index).distance_bus < temp.at(index).distance_taxi)
				{
					if (!S_distance[index] && (d_distance[index] > d_distance[u] + temp.at(index).distance_bus))
					{
						d_distance[index] = d_distance[u] + temp.at(index).distance_bus;
						p_distance[index] = u;
					}
				}
				else
				{
					if (!S_distance[index] && (d_distance[index] > d_distance[u] + temp.at(index).distance_taxi))
					{
						d_distance[index] = d_distance[u] + temp.at(index).distance_taxi;
						p_distance[index] = u;
					}
				}
			}
			else if (temp.at(index).distance_bus != 0 && temp.at(index).distance_train != 0)
			{
				if (temp.at(index).distance_bus < temp.at(index).distance_train)
				{
					if (!S_distance[index] && (d_distance[index] > d_distance[u] + temp.at(index).distance_bus))
					{
						d_distance[index] = d_distance[u] + temp.at(index).distance_bus;
						p_distance[index] = u;
					}
				}
				else
				{
					if (!S_distance[index] && (d_distance[index] > d_distance[u] + temp.at(index).distance_train))
					{
						d_distance[index] = d_distance[u] + temp.at(index).distance_train;
						p_distance[index] = u;
					}
				}
			}
			else if (temp.at(index).distance_taxi != 0 && temp.at(index).distance_train != 0)
			{
				if (temp.at(index).distance_taxi < temp.at(index).distance_train)
				{
					if (!S_distance[index] && (d_distance[index] > d_distance[u] + temp.at(index).distance_taxi))
					{
						d_distance[index] = d_distance[u] + temp.at(index).distance_taxi;
						p_distance[index] = u;
					}
				}
				else
				{
					if (!S_distance[index] && (d_distance[index] > d_distance[u] + temp.at(index).distance_train))
					{
						d_distance[index] = d_distance[u] + temp.at(index).distance_train;
						p_distance[index] = u;
					}
				}
			}
			else if (temp.at(index).distance_taxi != 0)
			{
				if (!S_distance[index] && (d_distance[index] > d_distance[u] + temp.at(index).distance_taxi))
				{
					d_distance[index] = d_distance[u] + temp.at(index).distance_taxi;
					p_distance[index] = u;
				}
			}
			else if (temp.at(index).distance_bus != 0)
			{
				if (!S_distance[index] && (d_distance[index] > d_distance[u] + temp.at(index).distance_bus))
				{
					d_distance[index] = d_distance[u] + temp.at(index).distance_bus;
					p_distance[index] = u;
				}
			}
			else if (temp.at(index).distance_train != 0)
			{
				if (!S_distance[index] && (d_distance[index] > d_distance[u] + temp.at(index).distance_train))
				{
					d_distance[index] = d_distance[u] + temp.at(index).distance_train;
					p_distance[index] = u;
				}
			}
		}

	}
}
void Matrix::DijkstraTime(int beginning)
{
	// Tworzymy tablice dynamiczne

	d_time = new int[vertices];

	p_time = new int[vertices];

	// Zbior S
	bool *S_time = new bool[vertices];


	// Inicjujemy tablice dynamiczne

	for (int i = 0; i < vertices; i++)
	{
		d_time[i] = MAXINT;
		p_time[i] = -1;

		S_time[i] = false;
	}
	// Koszty dojœcia v sa zerowe

	d_time[beginning] = 0;

	// Wyznaczamy œcie¿ki

	for (int i = 0; i < vertices; i++)
	{
		//Edge pw;
		int j, u, x = 0;

		// Szukamy wierzcho³ka w Q o najmniejszym koszcie d

		for (j = 0; S_time[j]; j++);
		for (u = j++; j < vertices; j++)
			if (!S_time[j] && (d_time[j] < d_time[u]))
				u = j;

		// Znaleziony wierzcho³ek przenosimy do S

		S_time[u] = true;

		// Modyfikujemy odpowiednio wszystkich s¹siadów u, którzy s¹ w Q

		vector<Edge> temp = matrix.at(u);

		for (int index = 0; index < matrix.size(); index++)
		{
			if (temp.at(index).time_bus != 0 && temp.at(index).time_taxi != 0 && temp.at(index).time_train != 0)
			{
				if (temp.at(index).time_bus < temp.at(index).time_taxi)
				{
					if (temp.at(index).time_bus < temp.at(index).time_train)
					{
						if (!S_time[index] && (d_time[index] > d_time[u] + temp.at(index).time_bus))
						{
							d_time[index] = d_time[u] + temp.at(index).time_bus;
							p_time[index] = u;
						}
					}
					else
					{
						if (!S_time[index] && (d_time[index] > d_time[u] + temp.at(index).time_train))
						{
							d_time[index] = d_time[u] + temp.at(index).time_train;
							p_time[index] = u;
						}
					}
				}
				else
				{
					if (temp.at(index).time_taxi < temp.at(index).time_train)
					{
						if (!S_time[index] && (d_time[index] > d_time[u] + temp.at(index).time_taxi))
						{
							d_time[index] = d_time[u] + temp.at(index).time_taxi;
							p_time[index] = u;
						}
					}
					else
					{
						if (!S_time[index] && (d_time[index] > d_time[u] + temp.at(index).time_train))
						{
							d_time[index] = d_time[u] + temp.at(index).time_train;
							p_time[index] = u;
						}
					}
				}
			}
			else if (temp.at(index).time_bus != 0 && temp.at(index).time_taxi != 0)
			{
				if (temp.at(index).time_bus < temp.at(index).time_taxi)
				{
					if (!S_time[index] && (d_time[index] > d_time[u] + temp.at(index).time_bus))
					{
						d_time[index] = d_time[u] + temp.at(index).time_bus;
						p_time[index] = u;
					}
				}
				else
				{
					if (!S_time[index] && (d_time[index] > d_time[u] + temp.at(index).time_taxi))
					{
						d_time[index] = d_time[u] + temp.at(index).time_taxi;
						p_time[index] = u;
					}
				}
			}
			else if (temp.at(index).time_bus != 0 && temp.at(index).time_train != 0)
			{
				if (temp.at(index).time_bus < temp.at(index).time_train)
				{
					if (!S_time[index] && (d_time[index] > d_time[u] + temp.at(index).time_bus))
					{
						d_time[index] = d_time[u] + temp.at(index).time_bus;
						p_time[index] = u;
					}
				}
				else
				{
					if (!S_time[index] && (d_time[index] > d_time[u] + temp.at(index).time_train))
					{
						d_time[index] = d_time[u] + temp.at(index).time_train;
						p_time[index] = u;
					}
				}
			}
			else if (temp.at(index).time_taxi != 0 && temp.at(index).time_train != 0)
			{
				if (temp.at(index).time_taxi < temp.at(index).time_train)
				{
					if (!S_time[index] && (d_time[index] > d_time[u] + temp.at(index).time_taxi))
					{
						d_time[index] = d_time[u] + temp.at(index).time_taxi;
						p_time[index] = u;
					}
				}
				else
				{
					if (!S_time[index] && (d_time[index] > d_time[u] + temp.at(index).time_train))
					{
						d_time[index] = d_time[u] + temp.at(index).time_train;
						p_time[index] = u;
					}
				}
			}
			else if (temp.at(index).time_taxi != 0)
			{
				if (!S_time[index] && (d_time[index] > d_time[u] + temp.at(index).time_taxi))
				{
					d_time[index] = d_time[u] + temp.at(index).time_taxi;
					p_time[index] = u;
				}
			}
			else if (temp.at(index).time_bus != 0)
			{
				if (!S_time[index] && (d_time[index] > d_time[u] + temp.at(index).time_bus))
				{
					d_time[index] = d_time[u] + temp.at(index).time_bus;
					p_time[index] = u;
				}
			}
			else if (temp.at(index).time_train != 0)
			{
				if (!S_time[index] && (d_time[index] > d_time[u] + temp.at(index).time_train))
				{
					d_time[index] = d_time[u] + temp.at(index).time_train;
					p_time[index] = u;
				}
			}
		}

	}
}
void Matrix::DijkstraShowDistance(int beginning, int end)
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

			for (int j = i; j > -1; j = p_distance[j])
				Stos[sptr++] = j;

			// Wypisujemy jej koszt

			cout << d_distance[i] << "  | ";
			// Wyœwietlamy œcie¿kê, pobieraj¹c wierzcho³ki ze stosu

			while (sptr)
				cout << Stos[--sptr] << " ";

			cout << endl;
			break;
		}
	}
}
void Matrix::DijkstraShowTime(int beginning, int end)
{
	cout << endl << "Najkorzystniejsza trasa ze wzgledu na czas";
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

			for (int j = i; j > -1; j = p_time[j])
				Stos[sptr++] = j;

			// Wypisujemy jej koszt

			cout << d_time[i] << "  | ";
			// Wyœwietlamy œcie¿kê, pobieraj¹c wierzcho³ki ze stosu

			while (sptr)
				cout << Stos[--sptr] << " ";

			cout << endl;
			break;
		}
	}
}

