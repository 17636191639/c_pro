/* main.c */
#include <stdio.h>
#include "ret_allocator.h"

int main(void)
{
     unit_t *p = alloc_unit();

     printf("number: %d\nmsg: %s\n", p->number, p->msg);
     free_unit(p);
     p = NULL;
     return 0;
}