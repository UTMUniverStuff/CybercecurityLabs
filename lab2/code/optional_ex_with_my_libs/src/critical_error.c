#include <stdio.h>
#include <stdlib.h>


void	critical_error(const char* msg)
{
	fprintf(stderr, "Critiacl error: %s\n", msg);
	exit(1);
}
