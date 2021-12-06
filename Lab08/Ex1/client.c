#include "client.h"
#include "util/util.h"

int main(int argc, char *argv[]) {
  node_t *root, *tmp;
  int id = 0;
  char *name = malloc_ck(20);
  int load;
  int passed;
  int n = 0;

  root = NULL;
  root = createEmptyTree();

  n = file_num_of_line_completed(argv[1], "r");
  FILE *f = open_file(argv[1], "r");
  for (int i = 0; i < n; i++) {
    fscanf(f, "%d %s %d %d", &id, name, &load, &passed);
    printf("%d %s %d %d\n", id, name, load, passed);
    root = insert(root, id, name, load, passed);
  }
  writeTree(f, root, PREORDER);
  return 0;
}
