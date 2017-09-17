#include <stdio.h>

#define QUEUESIZE		8
#define HEADSTART 		53
#define CYLINDERAMOUNT	200

int main(int argc, char const *argv[])
{
	int queue[QUEUESIZE] = {98, 183, 37, 122, 14, 124, 65, 67}

	int totalHeadMovement = 0;
	int currentHeadPos = HEADSTART;
	for(int i = 0; i < QUEUESIZE; i++){
		totalHeadMovement += queue[i] - currentHeadPos;
		currentHeadPos = queue[i]; 
	}
	printf("Total Head Movement: %d\n", totalHeadMovement);
	return 0;
}