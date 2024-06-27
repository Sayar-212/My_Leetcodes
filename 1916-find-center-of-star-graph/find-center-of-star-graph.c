int findCenter(const int** edges, const int edgesSize, const int* edgesColSize) {
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) return edges[0][0]; 
    else return edges[0][1];
}