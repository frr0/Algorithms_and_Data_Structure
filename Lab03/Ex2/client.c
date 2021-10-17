#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  printf("Hello World!\n"); 
  return 0;
}

/** Exercise 02 */
/** ----------- */
/**  */
/** A file contains data on a set of employees. */
/** For each employee there is a row of the file, including: */
/** * Last and first name (a single C string, maximum 50 characters, */
/**   e.g., Smith_John). */
/** * Personal identification (exactly 16 characters). */
/** * Data of hiring (format dd.mm.yyy, e.g, 30.05.2005). */
/** * Salary (integer value, in euro). */
/** Fields are space-separated. */
/** Employees do not appear in any specific order. */
/**  */
/** A C program receives 3 parameters on the command line: */
/** * Input file name (the format is the previously defined one). */
/** * A single strings, representing a last and first name pair (e.g., */
/**   Clinton_Bill). */
/** * A string made of only + and - characters (e.g., +++---+-+). */
/**  */
/** The program has to: */
/** * Read the file. */
/** * Store its content in a LIFO-logic list, but with two pointers for */
/**   each element one pointing ahead and one pointing behind the element */
/**   itself as: */
/**  */
/**   pHead  --> ----- --> ----- --> ----- --> ----- -X */
/**              |###|     |###|     |###|     |###| */
/**           X- ----- <-- ----- <-- ----- <-- ----- */
/**  */
/** * Find in the list the element storing the employee whose name is */
/** * passed on the command line as a second parameter. */
/** * Move along the list in the */
/**   - right direction for each '+' character */
/**   - left direction for each '-' character */
/**   in the third string parameter. */
/**   For each visited node of the list (including the first one) the */
/**   program has to print out (on standard output) all data of the */
/**   employee (with the same format this data appears in the original */
/**   input file). */
/**   If the end of the list is reached (in either side) the program has to */
/**   print-out the same element repeatedly. */
/**  */
/** Example */
/** ------- */
/**  */
/** Let the command line parameters be the following */
/**  */
/** file.txt Giallo_Antonio ---+ */
/**  */
/** and the file be the following */
/**  */
/** Rossi_Alberto AAABBBCCDEEFGGGH 03.12.1998 1845 */
/** Giallo_Antonio AAABBBCCDEEFGGGH 13.11.2007 1140 */
/** Verdi_Federica AAABBBCCDEEFGGGH 25.09.1989 2157 */
/** Bianchi_Elena AAABBBCCDEEFGGGH 15.02.2004 1345 */
/**  */
/** The file has to be stored in the LIFO structure as: */
/** Bianchi  ->  Verdi  -> Giallo  -> Rossi   */
/** Then, the program has to: */
/** - find Giallo_Antonio in the list and print its data */
/** - move let on Verdi and print its data (first -) */
/** - move left again and print Bianchi (second -) */
/** - do not move and print Bianchi again (third -) */
/** - move right and print Verdi (first +): */
/**  */
/** Giallo_Antonio AAABBBCCDEEFGGGH 13.11.2007 1140 */
/** Verdi_Federica AAABBBCCDEEFGGGH 25.09.1989 2157 */
/** Bianchi_Elena AAABBBCCDEEFGGGH 15.02.2004 1345 */
/** Bianchi_Elena AAABBBCCDEEFGGGH 15.02.2004 1345 */
/** Verdi_Federica AAABBBCCDEEFGGGH 25.09.1989 2157 */
/**  */
