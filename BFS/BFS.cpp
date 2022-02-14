// BFS.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <ctime>
#include <time.h>
#include <fstream>
using namespace std;

//int gSize = 6; // vertices of graph

void num_file(int size)
{
	vector<vector<int>> arr(size, vector<int>(size));
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (i == j) arr[i][j] = 0;
			else
			{
				arr[i][j] = rand() % 2;
				arr[j][i] = arr[i][j];
			}
		}
	}

	ofstream out;
	out.open("graph2.txt");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			out << arr[i][j] << " ";
		}
		out << endl;
	}
	out.close();
}

int main()
{
	int gSize = 0; // vertices of graph
	cout << "Enter number of the graph vertices: ";
	cin >> gSize;

	//srand(time(0));
	list<int>::iterator it;
	list<int> visited;
	list<int> toVisit;
	vector<bool> marked(gSize);
	//int gArr[gSize][gSize] = { { 0, 1, 1, 1, 0, 0 }, { 1, 0, 1, 0, 0, 0 }, { 1, 1, 0 , 0, 1, 0 }, { 1, 0, 0, 0, 0, 1 }, { 0, 0, 1, 0, 0, 1 }, { 0, 0, 0, 1, 1, 0 } };
	num_file(gSize);
	vector<vector<int>> gArr(gSize, vector<int>(gSize));
	ifstream in("graph2.txt");
	for (int i = 0; i < gSize; i++)
		for (int j = 0; j < gSize; j++)
			in >> gArr[i][j];
	in.close();

	double start_time = clock();

	toVisit.push_back(1); // put the first vertex in to the queue
	marked[0] = true; // mark first vertex
	int i = 0, j = 0;
	while (!toVisit.empty()) // while queue is not empty
	{
		i = toVisit.front() - 1; // make the firts vertex in the queue as the current vertex, i. e. visit that vertex
		visited.push_back(i); // [OPTIONAL] put the first vertex in "Visited" list
		toVisit.pop_front(); // delete the visited vertex from the queue
		for (j = 0; j < gSize; j++)
		{
			if (gArr[i][j] != 0) // if vertex has adjacent vertices
			{
				if (!marked[j]) // if vertex is not marked
				{
					toVisit.push_back(j + 1); // put vertex in to the queue
					marked[j] = true; // mark that vertex is in "To visit" list
				}
			}
		}
	}

	double end_time = clock();
	double search_time = end_time - start_time;
	cout << search_time / CLOCKS_PER_SEC << endl;

	/*for (it = visited.begin(); it != visited.end(); it++)
	{
		cout << *it << " ";
	}*/
}
