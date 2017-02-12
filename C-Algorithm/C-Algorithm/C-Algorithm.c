#include <stdio.h>
#include <limits.h>
#include <string.h>

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
	for (int k = 0; k < ROWS * COLS; k++)
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				MinDistance(dist, i, j, graph[i][j]);
			}
		}
	}

	printf("Last node: %d\n", dist[ROWS - 1][COLS - 1]);
}


int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		char const* const _graphFile = argv[1];

		FILE* graphFile = fopen(_graphFile, "r");

		char number[10];
		int inumber = 0;

		int i = 0, j = 0;

		memset(number, '\0', sizeof(number));
		int graph[ROWS][COLS];
		int c;
		while (EOF != (c = getc(graphFile)))
		{
			if (c != ' ')
			{
				while (EOF != c && c != ',')
				{
					strcat(number, &c);
					c = getc(graphFile);
				}

				char *ptr = &number;
				while (*ptr != '\0')
				{
					inumber *= 10;
					inumber += *ptr - '0';
					ptr++;
				}
				graph[i][j] = inumber;
				printf("{%d,%d} NUMBER->%d\n", i, j, graph[i][j]);
				memset(number, '\0', sizeof(number));
				inumber = 0;

				j++;
				if (j > COLS - 1)
				{
					i++;
					j = 0;
				}

			}
		}

		fcloseall();
		Dijkstra(graph);
	}
	else
	{
		fprintf(stderr, "Can't open graph file\n");
		return -1;
	}

	return 0;
}