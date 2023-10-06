#define V 6
#define TRUE 1
#define FALSE 0
#define min(X, Y) (((X) < (Y)) ? (X) : (Y))

int findPath(int [][V], int, int);

int fordFulkerson(int [][V], int, int);

int isEmpty();

void enqueue(int);

void dequeue();

int firstElem();

int augmentingPath[V] = {0, 0, 0, 0, 0, 0};

int queue[V];

int head = -1, tail = -1;

int findPath(int flowNetwork[][V], int s, int t){
	
	int visited[V];
	memset(visited, 0, sizeof(visited));

	enqueue(s);
	visited[s] = TRUE;
	augmentingPath[s] = -1;

	while(isEmpty(queue) == FALSE){
		
		int u = firstElem();
		dequeue();

		for(int v = 0; v < V; v++){
			
			if(visited[v] == FALSE && flowNetwork[u][v] > 0){
				
				if(v == t){

					augmentingPath[v] = u;
					return TRUE;
				}
				enqueue(v);
				augmentingPath[v] = u;
				visited[v] = TRUE;
			}			
		}
	}
	return FALSE;
}

int fordFulkerson(int flowNetwork[][V], int s, int t){
	
	int u = 0, v = 0, maxFlow = 0, residualGraph[V][V];

	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			residualGraph[i][j] = flowNetwork[i][j];
		}
	}

	while(findPath(residualGraph, s, t) == TRUE){

		int pathFlow = INT_MAX;
		
		for(v = t; v != s; v = augmentingPath[v]){

			u = augmentingPath[v];
			pathFlow = min(pathFlow, residualGraph[u][v]);
		}

		for(v = t; v != s; v = augmentingPath[v]){

			u = augmentingPath[v];
			residualGraph[u][v] -= pathFlow;
			residualGraph[v][u] += pathFlow;
		}

		maxFlow += pathFlow;
	}

	return maxFlow;
}

int isEmpty(){
	
	if(head == -1 && tail == -1) return TRUE;
	else return FALSE;
}

void enqueue(int x){

	if(isEmpty() == TRUE){

		head = 0;
		tail = 0;
	} else {

		tail++;
	}

	queue[tail] = x;
}

void dequeue(){

	if(head == tail){

		head = -1;
		tail = -1;
	} else {

		head++;
	}
}

int firstElem(){

	return queue[head];
}