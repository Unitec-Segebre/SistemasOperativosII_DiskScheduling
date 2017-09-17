#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define QUEUESIZE		8
#define HEADSTART 		53

int getShortestSeekTime(int* queue, char* done, int queueLength, int* current);
int main(int argc, char const *argv[])
{
	int queue[QUEUESIZE] = {98, 183, 37, 122, 14, 124, 65, 67};
	char done[QUEUESIZE] = {0};

	int totalHeadMovement = 0;
	int currentHeadPos = HEADSTART;
	for(int i = 0; i < QUEUESIZE; i++){
		totalHeadMovement += getShortestSeekTime(queue, done, QUEUESIZE, &currentHeadPos);
	}
	printf("Total Head Movement: %d\n", totalHeadMovement);
	return 0;
}

int getShortestSeekTime(int* queue, char* done, int queueLength, int* current){
	int shortestLength = INT_MAX;
	int indexToMark = -1;
	int previousHeadPos = *current;
	for (int i = 0; i < queueLength; i++)
	{
		if(!done[i] && abs(previousHeadPos-queue[i]) < shortestLength){
			shortestLength = abs(previousHeadPos-queue[i]);
			*current = queue[i];
			indexToMark = i;
		}
	}
	done[indexToMark] = 1;
	return abs(previousHeadPos - *current);
}