#include <stdio.h>
#include <stdlib.h>
#define MAX_RAND_COORD 10000
#define RAND_MULTIPLIER 1.e-2
#define MAX_POLY_SIZE 100000
#define MIN_POLY_SIZE 3

typedef struct Point
{
	double x;
	double y;
} Point;

typedef struct SPolygon
{
	Point *points;
	int n;
} SPolygon;

void generate(SPolygon *poly, int n);
void print(SPolygon poly);
void clear(SPolygon poly);

void generate(SPolygon *poly, int n)
{
        poly->n = n;
	poly->points = (Point*)malloc(n*sizeof(Point));
        for (int k=0; k<n; k++) 
	{
		(poly->points[k]).x = (rand() % (2*MAX_RAND_COORD + 1) - MAX_RAND_COORD) * RAND_MULTIPLIER;
		(poly->points[k]).y = (rand() % (2*MAX_RAND_COORD + 1) - MAX_RAND_COORD) * RAND_MULTIPLIER;
	}
}

void print(SPolygon poly)
{
	printf("Polygon: {");
	for (int k=0; k<poly.n; k++) printf("(%.2lf; %.2lf), ", poly.points[k].x, poly.points[k].y);
	printf("\b\b}\n");
}

void clear(SPolygon poly)
{
	free(poly.points);
}

int main(void)
{
        int n;
        SPolygon poly;
	printf("Enter number of points: ");
        if (scanf("%d", &n) !=1 ) return -1;
	if (n < MIN_POLY_SIZE || n > MAX_POLY_SIZE) return -2;
	generate(&poly, n);
	print(poly);
	clear(poly);
	return 0;
}