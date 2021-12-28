#ifndef _GRAPH_EXT
#define _GRAPH_EXT

#include "graph.h"
#include "queuePublic.h"

void graph_bfs1(graph_t *, vertex_t *);
void graph_dfs1(graph_t *, vertex_t *);
int graph_dfs_r1(graph_t *, vertex_t *, int);

int graph_bfs_count(int );
void graph_bfs_distance();
void graph_dfs_type();
void graph_dfs_depth();
void graph_dfs_r_max_path();

#endif
