#include "client.h"
#include "util.h"

int main(int argc, char *argv[])
{
  int n1 = 0;
  int n2 = 0;
  arg_check(argc, argv);
  /** open_file(argv[1], "r"); */
  file_num_of_line_completed(argv[1], "r", n1);
  /** open_file(argv[2], "r"); */
  file_num_of_line_completed(argv[2], "r", n2);
  return 0;
}
