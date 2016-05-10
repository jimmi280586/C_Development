#include "stdio.h"

void main() {
   FILE *fp;

   fp = fopen("/home/jimmi/C_Development/ReadFile_WriteFile/test.txt", "w+");
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);
}
