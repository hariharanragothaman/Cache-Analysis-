/* cache.c */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cache.h"
#include "main.h"
/* cache configuration parameters */
static int cache_split = 0;
static int cache_usize = DEFAULT_CACHE_SIZE;
static int cache_isize = DEFAULT_CACHE_SIZE;
static int cache_dsize = DEFAULT_CACHE_SIZE;
static int cache_block_size = DEFAULT_CACHE_BLOCK_SIZE;
static int words_per_block = DEFAULT_CACHE_BLOCK_SIZE / WORD_SIZE;
static int cache_assoc = DEFAULT_CACHE_ASSOC;
static int cache_writeback = DEFAULT_CACHE_WRITEBACK;
static int cache_writealloc = DEFAULT_CACHE_WRITEALLOC;

/* cache model data structures */
static Pcache icache;
static Pcache dcache;
static cache c1;
static cache c2;
static cache_stat cache_stat_inst;
static cache_stat cache_stat_data;
**************************************************************************

void set_cache_param(param, value)
{
int param;
int value;
{
switch (param)
{
case CACHE_PARAM_BLOCK_SIZE:
cache_block_size = value;
words_per_block = value / WORD_SIZE;
break;

case CACHE_PARAM_USIZE:
cache_split = FALSE;
cache_usize = value;
break;

case CACHE_PARAM_ISIZE:
cache_split = TRUE;
cache_isize = value;
break;

case CACHE_PARAM_DSIZE:
cache_split = TRUE;
cache_dsize = value;
break;

case CACHE_PARAM_ASSOC:
cache_assoc = value;
break;

case CACHE_PARAM_WRITEBACK:
cache_writeback = TRUE;
break;

case CACHE_PARAM_WRITETHROUGH:
cache_writeback = FALSE;
break;

case CACHE_PARAM_WRITEALLOC:
cache_writealloc = TRUE;
break;

case CACHE_PARAM_NOWRITEALLOC:
cache_writealloc = FALSE;
break;

default:
printf("error set_cache_param: bad parameter value\n");
exit(-1);
}
}
}







