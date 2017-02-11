#include <stdio.h>
#include <limits.h>

#define COLS 3 
#define ROWS 3 

void MinDistance(int dist[ROWS][COLS], int currentI, int currentJ, int value)
{

	if (currentI - 1 >= 0)
	{
		int src = dist[currentI - 1][currentJ];
		if (src != INT_MAX)
			if (src + value < dist[currentI][currentJ])
				dist[currentI][currentJ] = src + value;
	}

	if (currentI + 1 <= ROWS - 1)
	{
		int src = dist[currentI + 1][currentJ];
		if (src != INT_MAX)
			if (src < dist[currentI][currentJ])
				dist[currentI][currentJ] = src + value;
	}

	if (currentJ - 1 >= 0)
	{
		int src = dist[currentI][currentJ - 1];
		if (src != INT_MAX)
			if (src + value < dist[currentI][currentJ])
				dist[currentI][currentJ] = src + value;
	}

	if (currentJ + 1 <= COLS - 1)
	{
		int src = dist[currentI][currentJ + 1];
		if (src != INT_MAX)
			if (src + value < dist[currentI][currentJ])
				dist[currentI][currentJ] = src + value;
	}
}

void Dijkstra(int graph[ROWS][COLS])
{
	int dist[ROWS][COLS];

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			dist[i][j] = INT_MAX;
		}
	}
	dist[0][0] = 0;

	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				MinDistance(dist, i, j, graph[i][j]);
				printf("GRAPH->%d ", graph[i][j]);
				printf("{%d,%d} %d\n", i, j, dist[i][j]);
			}
		}
		printf("-------------\n");
	}


}

int main()
{
	int graph[ROWS][COLS];
	graph[0][0] = 0;
	graph[0][1] = 13;
	graph[0][2] = 5;

	graph[1][0] = 4;
	graph[1][1] = 5;
	graph[1][2] = 2;

	graph[2][0] = 1;
	graph[2][1] = 6;
	graph[2][2] = 9;

	Dijkstra(graph);
	return 0;
}