#include "paths.h"

int escape1(char **m, int r, int c) {
  if (r < 0 || r > R || c < 0 || c > C) {
    return 0;
  }
  if (m[r][c] == '*') {
    /** m[r][c] = 'W'; */
    return 0;
  }
  if (m[r][c] == '#') {
    printf("\nEXITED!!");
    return 1;
  }
  if (m[r][c] == 'X') {
    m[r][c] = 'o';
    return 0;
  }
  if (m[r][c] == '@') {
    return escape1(m, r - 1, c) || escape1(m, r + 1, c) ||
           escape1(m, r, c - 1) || escape1(m, r, c + 1);
  }
  if (m[r][c] == ' ') {
    m[r][c] = 'X';
    return escape1(m, r, c + 1) || escape1(m, r + 1, c) ||
           escape1(m, r, c - 1) || escape1(m, r - 1, c);
  }

  return 0;
}

int escape2(char **m, int r, int c) {
  if (r < 0 || r > R || c < 0 || c > C) {
    return 0;
  }
  if (m[r][c] == '*') {
    /** m[r][c] = 'W'; */
    return 0;
  }
  if (m[r][c] == '#') {
    printf("\nEXITED!!");
    return 1;
  }
  if (m[r][c] == 'X') {
    m[r][c] = 'o';
    return 0;
  }
  if (m[r][c] == '@') {
    return escape1(m, r - 1, c) || escape1(m, r + 1, c) ||
           escape1(m, r, c - 1) || escape1(m, r, c + 1);
  }
  if (m[r][c] == ' ') {
    m[r][c] = 'X';
    return escape1(m, r, c + 1) || escape1(m, r + 1, c) ||
           escape1(m, r, c - 1) || escape1(m, r - 1, c);
  }

  return 0;
}

int escape3(char **m, int r, int c) {
  if (r < 0 || r > R || c < 0 || c > C) {
    return 0;
  }
  if (m[r][c] == '*') {
    /** m[r][c] = 'W'; */
    return 0;
  }
  if (m[r][c] == '#') {
    printf("\nEXITED!!");
    return 1;
  }
  if (m[r][c] == 'X') {
    m[r][c] = 'o';
    return 0;
  }
  if (m[r][c] == '@') {
    return escape1(m, r - 1, c) || escape1(m, r + 1, c) ||
           escape1(m, r, c - 1) || escape1(m, r, c + 1);
  }
  if (m[r][c] == ' ') {
    m[r][c] = 'X';
    return escape1(m, r, c + 1) || escape1(m, r + 1, c) ||
           escape1(m, r, c - 1) || escape1(m, r - 1, c);
  }

  return 0;
}
