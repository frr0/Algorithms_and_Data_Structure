#include "graph_extended.h"

int graph_bfs_count(int nb) { return ++nb; }

void graph_dfs_distance(graph_t *g, vertex_t *n) {
  queue_t *qp;
  vertex_t *d;
  edge_t *e;
  int dist_each[g->nv];
  int dist = 0;
  int n_vertex = 0;
  int max = 0;

  qp = queue_init(g->nv);
  n->color = GREY;
  n->dist = 0;
  n->pred = NULL;
  queue_put(qp, (void *)n);

  while (!queue_empty_m(qp)) {
    queue_get(qp, (void **)&n);
    e = n->head;
    while (e != NULL) {
      d = e->dst;
      if (d->color == WHITE) {
        d->color = GREY;
        d->dist = n->dist + 1;
        d->pred = n;
        /** dist++; */
        queue_put(qp, (void *)d);
      }
      e = e->next;
    }
    n->color = BLACK;
  }
  queue_dispose(qp, NULL);

  /** dist_each[n_vertex++] = dist; */
  /**  */
  /** for (int i = 0; i < g->nv; i++) { */
  /**   if (dist_each[i] > max) { */
  /**     max = dist_each[i]; */
  /**   } */
  /** } */
  /**  */
  /** printf("The further vertex is a distance %d\n", max); */

  return;
}

void graph_dfs1(graph_t *g, vertex_t *n) {
  int currTime = 0;
  vertex_t *tmp, *tmp2;

  printf("List of edges:\n");
  currTime = graph_dfs_r1(g, n, currTime);
  for (tmp = g->g; tmp != NULL; tmp = tmp->next) {
    if (tmp->color == WHITE) {
      currTime = graph_dfs_r1(g, tmp, currTime);
    }
  }

  printf("List of vertices:\n");
  for (tmp = g->g; tmp != NULL; tmp = tmp->next) {
    tmp2 = tmp->pred;
    printf("%2d: %2d/%2d (%d)\n", tmp->id, tmp->disc_time, tmp->endp_time,
           (tmp2 != NULL) ? tmp->pred->id : -1);
  }
}

/*
 *  perform recursive DFS from vertex i:
 *  labels nodes with td/tq, edges as T/F/B/C
 */
int graph_dfs_r1(graph_t *g, vertex_t *n, int currTime) {
  edge_t *e;
  vertex_t *tmp;

  n->color = GREY;
  n->disc_time = ++currTime;
  e = n->head;
  while (e != NULL) {
    tmp = e->dst;
    switch (tmp->color) {
    case WHITE:
      printf("%d -> %d : T\n", n->id, tmp->id);
      break;
    case GREY:
      printf("%d -> %d : B\n", n->id, tmp->id);
      break;
    case BLACK:
      if (n->disc_time < tmp->disc_time) {
        printf("%d -> %d : F\n", n->disc_time, tmp->disc_time);
      } else {
        printf("%d -> %d : C\n", n->id, tmp->id);
      }
    }
    if (tmp->color == WHITE) {
      tmp->pred = n;
      currTime = graph_dfs_r1(g, tmp, currTime);
    }
    e = e->next;
  }
  n->color = BLACK;
  n->endp_time = ++currTime;

  return currTime;
}
