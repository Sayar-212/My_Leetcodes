//C Code
#define lower_bound  1e-5 
typedef struct _node{
    int next ;
    double val ;
}node ;

void DFS(int n, bool* visited, double val, double* ans, int cur, int end, int* cn, node** map){ 
    if( cur == end ){
        *ans = fmax(*ans, val) ;
    }  
    if(*ans >= val)
        return ;
    if((val - *ans) <= lower_bound )
        return ;
    if( visited[cur] == true )
        return ;
    visited[cur] = true ;
    for(int i = 0; i < cn[cur]; i++){    
        double new_val = val * map[cur][i].val ;
        DFS(n, visited, new_val, ans, map[cur][i].next, end, cn, map) ;
    }
    visited[cur] = false ;
}


double maxProbability(int n, int** edges, int edgesSize, int* edgesColSize, double* succProb, int succProbSize, int start, int end){
    double ans = 0 ;
    bool* visited = calloc( n, sizeof(bool) ) ;
   
    int* cn = calloc(n, sizeof(int) ) ;
    node** map = calloc(n , sizeof(node*) ) ;
    for(int i = 0; i < edgesSize; i++){
        cn[edges[i][0]]++ ;
        cn[edges[i][1]]++ ;
    }
    for(int i = 0; i < n; i++){
        if(cn[i]){
            map[i] = malloc(cn[i] * sizeof(node)) ;
        }
    }
    int* m_idx = calloc(n , sizeof(int) ) ;
    for(int i = 0; i < edgesSize; i++){
        int p = edges[i][0] ;
        int next = edges[i][1] ;
        int idx = m_idx[p] ;
        map[p][idx].next = next ;
        map[p][idx].val = succProb[i] ;
        m_idx[p]++;
        
        p = edges[i][1] ;
        next = edges[i][0] ;
        idx = m_idx[p] ;
        map[p][idx].next = next ;
        map[p][idx].val = succProb[i] ;
        m_idx[p]++;
    } 

    DFS(n, visited, 1.0, &ans, start, end, cn, map) ;
    free(visited) ;
    for(int i = 0; i < n; i++){
        if(cn[i])
            free(map[i]) ;
    }
    free(cn) ;
    free(map) ;
    return ans ;
}