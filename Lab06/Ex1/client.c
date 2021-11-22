#include "client.h"

int main(int argc, char **argv) {
  char **m;
  m = scanmat(argc, argv);
  /** printmat(m, argc, argv); */
  return 0;
}

/** A file includes a labyrinth with the following specifications: */
/** - the first line of the file specifies the number of row R and the */
/**   number of columns C of a matrix */
/** - the following R lines specify the matrix rows (each one with C */
/**   characters), where each */
/**   - '@' indicates the initial position of a human being */
/**   - ' ' represents corridors (empty cells) */
/**   - '*' represents walls (full cells) */
/**   - '#' represents exit points. */
/** Suppose that only one person is present in the maze in the initial */
/** configuration. */
/**  */
/** The following is a correct example of such a maze: */
/**  */
/** 12 10 */
/** ********** */
/** *        * */
/** *   **@* * */
/** * * ** * * */
/** * ****** * */
/** *   **   * */
/** * *    *** */
/** * ** * ***  */
/** * *  * * * */
/** * * ** * * */
/** *   **   * */
/** ******#*** */
/**  */
/** Write three recursive functions to find: */
/** - one escape path */
/** - all escape paths */
/** - the shortest escape path */
/** from the maze. */
/** Print out the solution (or all solutions) on standard output. */
/**  */
/** Observation */
/** ----------- */
/**  */
/** To avoid extremely long running times, check the program on small */
/** mazes or on mazes on which the number (and length) of escaping */
/** paths is limited. */
