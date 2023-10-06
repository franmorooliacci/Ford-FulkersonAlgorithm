#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "fordFulkerson.h"


int main(){
	
	int flowNetwork[V][V] = { {0, 4, 6, 0, 0, 0},
					  		{0, 0, 0, 3, 5, 0},
					  		{0, 0, 0, 0, 6, 0},
					  		{0, 0, 9, 0, 0, 5},
					  		{0, 0, 0, 0, 0, 4},
					  		{0, 0, 0, 0, 0, 0}	};

	printf("The maximum flow is: %d\n", fordFulkerson(flowNetwork, 0, V-1));
	
	return 0;
}