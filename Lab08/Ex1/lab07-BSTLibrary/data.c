#include "data.h"
#include <stdio.h>

int readData(FILE *fp, data_t *data) {
  int retValue;

  retValue = fscanf(fp, "%d", data);

  return (retValue);
}

void writeData(FILE *fp, data_t data) {
  fprintf(stdout, "%d %s %d %d\n", data.id, data.name, data.load, data.passed);

  return;
}

int compare_id(int i1, int i2) {

  if (i1 < i2) {
    return (-1);
  } else {
    if (i1 == i2) {
      return (0);
    } else {
      return (1);
    }
  }
}

int compare(data_t d1, data_t d2) {
  /** if (d1.id < d2.id) { */
  /**   return (-1); */
  /** } else { */
  /**   if (d1.id == d2.id) { */
  /**     return (0); */
  /**   } else { */
  /**     return (1); */
  /**   } */
  /** } */
  return compare_id(d1.id, d2.id);
}
