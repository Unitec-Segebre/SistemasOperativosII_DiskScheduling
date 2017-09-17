#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define QUEUESIZE		8
#define HEADSTART 		53
#define CYLINDERAMOUNT	200

int getNextPosition(int* queue, char* done, int queueLength, int* current, char* direction);
int main(int argc, char const *argv[])
{
	int queue[QUEUESIZE] = {98, 183, 37, 122, 14, 124, 65, 67};
	char done[QUEUESIZE] = {0};

	int totalHeadMovement = 0;
	int currentHeadPos = HEADSTART;
	char direction = 0;
	for(int i = 0; i < QUEUESIZE; i++){
		totalHeadMovement += getNextPosition(queue, done, QUEUESIZE, &currentHeadPos, &direction);
	}
	printf("Total Head Movement: %d\n", totalHeadMovement);
	return 0;
}

int getNextPosition(int* queue, char* done, int queueLength, int* current, char* direction){
	int shortestLength = INT_MAX;
	int indexToMark = -1;
	int previousHeadPos = *current;
	for (int i = 0; i < queueLength; i++)
	{
		if(!done[i] && ((*direction && queue[i]>=previousHeadPos) || (!*direction && queue[i]<previousHeadPos)) && abs(previousHeadPos-queue[i]) < shortestLength){
			shortestLength = abs(previousHeadPos-queue[i]);
			*current = queue[i];
			indexToMark = i;
		}
	}
	if(indexToMark == -1){
		int headMovement;
		if(*direction)
			headMovement = CYLINDERAMOUNT - *current;
		else
			headMovement = *current;
		headMovement = headMovement<<1;
		*direction = !*direction;
		return headMovement + getNextPosition(queue, done, queueLength, current, direction);
	}
	done[indexToMark] = 1;
	return abs(previousHeadPos - *current);
}