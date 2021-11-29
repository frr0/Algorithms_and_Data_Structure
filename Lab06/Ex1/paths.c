#include "paths.h"

int escape1(char **m, char **mm, int r, int c) {
  if (r < 0 || r > R || c < 0 || c > C) {
    return 0;
  }
  if (m[r][c] == '*') {
    return 0;
  }
  if (m[r][c] == '#') {
    printf("\nEXITED!!");
    return 1;
  }
  if (m[r][c] == 'X') {
    m[r][c] = 'x';
    return 0;
  }
  if (m[r][c] == '@') {
    return escape1(m, mm, r + 1, c) || escape1(m, mm, r, c + 1) ||
           escape1(m, mm, r, c - 1) || escape1(m, mm, r - 1, c);
  }
  if (m[r][c] == ' ') {
    m[r][c] = 'X';
    return escape1(m, mm, r + 1, c) || escape1(m, mm, r, c + 1) ||
           escape1(m, mm, r, c - 1) || escape1(m, mm, r - 1, c);
  }

  return 0;
}

int escape2(char **m, int r, int c) {
  int n = 0, nn = 0;

  if (r < 0 || r > R || c < 0 || c > C) {
    return 0;
  }
  if (m[r][c] == '*') {
    return 0;
  }
  if (m[r][c] == '#') {
    printf("\nEXITED # %d !!", n++);
    printmat2(m);
    escape2(m, 2, 6);
    nn++;
    return 0;
  }
  if (m[r][c] == 'X') {
    if (nn == n) {
      m[r][c] = ' ';
    }
    return 0;
  }
  if (m[r][c] == '@') {
    return escape2(m, r - 1, c) || escape2(m, r + 1, c) ||
           escape2(m, r, c - 1) || escape2(m, r, c + 1);
  }
  if (m[r][c] == ' ') {
    m[r][c] = 'X';
    return escape2(m, r, c + 1) || escape2(m, r + 1, c) ||
           escape2(m, r, c - 1) || escape2(m, r - 1, c);
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
    return escape3(m, r - 1, c) || escape3(m, r + 1, c) ||
           escape3(m, r, c - 1) || escape3(m, r, c + 1);
  }
  if (m[r][c] == ' ') {
    m[r][c] = 'X';
    return escape3(m, r, c + 1) || escape3(m, r + 1, c) ||
           escape3(m, r, c - 1) || escape3(m, r - 1, c);
  }

  return 0;
}
