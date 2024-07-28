typedef struct {
    int node;
    int time;
} State;

typedef struct {
    State* data;
    int size;
    int capacity;
} MinHeap;

void swap(State* a, State* b) {
    State temp = *a;
    *a = *b;
    *b = temp;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (State*)malloc(capacity * sizeof(State));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->data[left].time < heap->data[smallest].time)
        smallest = left;

    if (right < heap->size && heap->data[right].time < heap->data[smallest].time)
        smallest = right;

    if (smallest != idx) {
        swap(&heap->data[idx], &heap->data[smallest]);
        minHeapify(heap, smallest);
    }
}

State extractMin(MinHeap* heap) {
    if (heap->size <= 0)
        return (State){-1, -1};
    
    if (heap->size == 1) {
        heap->size--;
        return heap->data[0];
    }

    State root = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);

    return root;
}

void insertMinHeap(MinHeap* heap, State k) {
    if (heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = (State*)realloc(heap->data, heap->capacity * sizeof(State));
    }

    heap->size++;
    int i = heap->size - 1;
    heap->data[i] = k;

    while (i != 0 && heap->data[(i - 1) / 2].time > heap->data[i].time) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void freeMinHeap(MinHeap* heap) {
    free(heap->data);
    free(heap);
}

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node** heads;
    int* sizes;
    int size;
} Graph;

Graph* createGraph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->heads = (Node**)malloc((n + 1) * sizeof(Node*));
    graph->sizes = (int*)calloc(n + 1, sizeof(int));
    graph->size = n;

    for (int i = 0; i <= n; i++) {
        graph->heads[i] = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = v;
    node->next = graph->heads[u];
    graph->heads[u] = node;

    node = (Node*)malloc(sizeof(Node));
    node->val = u;
    node->next = graph->heads[v];
    graph->heads[v] = node;

    graph->sizes[u]++;
    graph->sizes[v]++;
}

void freeGraph(Graph* graph) {
    for (int i = 0; i <= graph->size; i++) {
        Node* head = graph->heads[i];
        while (head) {
            Node* temp = head;
            head = head->next;
            free(temp);
        }
    }
    free(graph->heads);
    free(graph->sizes);
    free(graph);
}

int secondMinimum(int n, int** edges, int edgesSize, int* edgesColSize, int time, int change) {
    Graph* graph = createGraph(n);
    for (int i = 0; i < edgesSize; i++) {
        addEdge(graph, edges[i][0], edges[i][1]);
    }

    int* minTime = (int*)malloc((n + 1) * sizeof(int));
    int* secondMinTime = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++) {
        minTime[i] = INT_MAX;
        secondMinTime[i] = INT_MAX;
    }

    MinHeap* pq = createMinHeap(edgesSize * 2);
    insertMinHeap(pq, (State){1, 0});
    minTime[1] = 0;

    while (pq->size > 0) {
        State curr = extractMin(pq);
        int currNode = curr.node;
        int currTime = curr.time;

        Node* neighborNode = graph->heads[currNode];
        while (neighborNode) {
            int neighbor = neighborNode->val;
            int waitTime = 0;
            if ((currTime / change) % 2 == 1) {
                waitTime = change - (currTime % change);
            }
            int nextTime = currTime + time + waitTime;

            if (nextTime < minTime[neighbor]) {
                secondMinTime[neighbor] = minTime[neighbor];
                minTime[neighbor] = nextTime;
                insertMinHeap(pq, (State){neighbor, nextTime});
            } else if (nextTime > minTime[neighbor] && nextTime < secondMinTime[neighbor]) {
                secondMinTime[neighbor] = nextTime;
                insertMinHeap(pq, (State){neighbor, nextTime});
            }

            neighborNode = neighborNode->next;
        }
    }

    int result = secondMinTime[n];
    free(minTime);
    free(secondMinTime);
    freeMinHeap(pq);
    freeGraph(graph);

    return result;
}