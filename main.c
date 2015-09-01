#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define OPT_LIST "f:"

int
main (int argc, char **argv)
{
  char *fflag = 0;
  char *cvalue = NULL;
  int index;

  opterr = 0;
  while ((c = getopt (argc, argv, OPT_LIST)) != -1)
    switch (c)
      {
      case 'f':
        fflag = 1;
        break;
      case '?':
        if (optopt == 'f')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }
  printf ("aflag = %d, bflag = %d, cvalue = %s\n",
          aflag, bflag, cvalue);

  for (index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);
  return 0;
}
