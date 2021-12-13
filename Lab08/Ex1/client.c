#include "client.h"
#include "lab07-BSTLibrary/treePublic.h"
#include "lab08-HTLibrary/item.h"
#include "lab08-HTLibrary/st.h"
#include "util/util.h"

int main(int argc, char *argv[]) {
  node_t *root /**, *tmp */;
  int id = 0;
  char *name = malloc_ck(20);
  int load;
  int passed;
  int n = 0;

  Key k;
  int i, cont, maxN;
  Item item;
  ST st = STinit(maxN);

  n = file_num_of_line_completed(argv[1], "r");
  FILE *f = open_file(argv[1], "r");
  for (int i = 0; i < n; i++) {
    fscanf(f, "%d %s %d %d", &id, name, &load, &passed);
    printf("%d %s %d %d\n", id, name, load, passed);
    root = insert(root, id, name, load, passed);
  }
  printf("\n===== INORDER =====\n");
  writeTree(f, root, INORDER);
  printf("\n===== PREORDER =====\n");
  writeTree(f, root, PREORDER);
  printf("\n===== POSTORDER =====\n");
  writeTree(f, root, POSTORDER);

  fprintf(stdout, "Hash table size: ");
  scanf("%d", &maxN);

  root = NULL;
  root = createEmptyTree();

  while (cont) {
    fprintf(stdout,
            "Operations (1:Insert, 2:Search, 3:Delete, 4:Display, 5:Exit): ");
    scanf("%d", &i);

    switch (i) {
    case 1:
      fprintf(stdout, "  Enter item (name <space> value): ");
      item = ITEMscan();
      if (ITEMcheckvoid(STsearch(st, KEYget(item))))
        STinsert(st, item);
      break;
    case 2:
      fprintf(stdout, "  Enter key: ");
      k = KEYscan();
      if (ITEMcheckvoid(STsearch(st, k)))
        fprintf(stdout, "  Data not found!\n");
      else
        fprintf(stdout, "  Data found!\n");
      break;
    case 3:
      fprintf(stdout, "  Enter key: ");
      k = KEYscan();
      if (ITEMcheckvoid(STsearch(st, k)))
        fprintf(stdout, "  Data not found!\n");
      else
        STdelete(st, k);
      break;
    case 4:
      STdisplay(st);
      break;
    case 5:
      cont = 0;
      break;
    default:
      fprintf(stdout, "  Invalid option\n");
      break;
    }
  }

  return 0;
}
