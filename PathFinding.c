#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GRID_SIZE 256
#define DIAGONAL_COEF 1.5
#define REALLY_FAR_AWAY 99999

//gcc -Wall -pedantic -std=c99 PathFinding.c && ./a.out < sample_input.txt

int getWeight(char in) {
	switch(in) {
		case '.':
			return 1;
		case ',':
			return 2;
		case 'o':
			return 3;
		case '=':
			return 50;
		case '0':
			return REALLY_FAR_AWAY;
		case '1':
			return REALLY_FAR_AWAY;
		case '2':
			return 0;
		case '3':
			return REALLY_FAR_AWAY;
		case '\n':
			return REALLY_FAR_AWAY;
	}
	return REALLY_FAR_AWAY;
}

// heap sort code:
void swap(int* heap, int a, int b) {
	int temp = heap[a];
	heap[a] = heap[b];
	heap[b] = temp;
}

void heapUp(int* heap, int index) {
	int parentIndex = index >> 1; //(int)(index/2)
	while((index != 0) && (heap[index] > heap[parentIndex])) {
		swap(heap, index, parentIndex);
		index = parentIndex;
		parentIndex = index >> 1;
	}
}

void heapDown(int* heap, int index, int heapSize) {
	int left = (index << 1)+1;
	int right = left + 1;
	while ((right < heapSize) || (left < heapSize)) {
		if ((heap[right] > heap[left]) && (heap[right] > heap[index])) {
			swap(heap, index, right);

			index = right;
			left = (index << 1)+1;
			right = left + 1;
		} else {
			if (heap[left] > heap[index]) {
				swap(heap, index, left);

				index = left;
				left = (index << 1)+1;
				right = left + 1;
			} else {
				return;
			}
		}

	}
}

int main() {

	clock_t start;
	double timeSeconds = 0;
	double timeMicroseconds = 0;

	int mapSize = (MAX_GRID_SIZE+1) * MAX_GRID_SIZE;
	/*
	char mapBuf[mapSize];
	memset(mapBuf, '\0', mapSize*sizeof(char));
	*/
	char *mapArr = calloc(mapSize, sizeof(char));
	int *visited = calloc(mapSize, sizeof(int));
	char ch;
	int i, j, vIndex, startIndex, endIndex = 0;

	while(scanf("%c", &ch) != EOF) {
		//printf("%c", ch);
		if (ch == '\n') {
			j++;
		} 
		if (ch != ' ') {
			mapArr[i + j*MAX_GRID_SIZE] = ch;
			i++;
			if (ch == '0') {
				startIndex = i + j*MAX_GRID_SIZE;
			}
			if (ch == '2') {
				endIndex = i + j*MAX_GRID_SIZE;
			}
		}
	}

	// A*
	int neighbors[8];

	neighbors[0] = getWeight(mapArr[])
	
	printf("\n--------\n");
	
	for (int k = 0; k < mapSize; k++) {
		
		if (k % MAX_GRID_SIZE == 0) {
			//printf("\n");
		}
		printf("%c", mapArr[k]);
	}

	timeSeconds = (double)(clock() - start) / CLOCKS_PER_SEC;
	timeMicroseconds = timeSeconds * 1000000.0;
	printf("\nTime taken in microseconds: %f\n", timeMicroseconds);

	free(mapArr);
	free(visited);
	return 0;
}
