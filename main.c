#include <stdlib.h>
#include <stdio.h>
#include "cache.h"
#include "main.h"
static FILE *traceFile;
int main(argc, argv)
int argc;
char **argv;
{
parse_args(argc, argv);
init_cache();
play_trace(traceFile);
print_stats();
}
