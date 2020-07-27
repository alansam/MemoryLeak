#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int a;
	int c;
	double b;
	long long int d;
} MYSTRUCT;

#define COUNT 4
#define MAX_SIZE 24

int main()
{
	MYSTRUCT *p, *q;
	void* v;

	printf("size of MYSTRUCT = %zu\n", sizeof(MYSTRUCT));
	
	p = /*(MYSTRUCT*)*/calloc(COUNT, /*MAX_SIZE*/sizeof(MYSTRUCT));

	for (int i = 0; i < COUNT; i++)
	{
		p[i].a = i;
		p[i].b = 10000000000.0 + i;
		p[i].c = i * 20;
		p[i].d = 4294967296 + i;
	}

  q = p;
  for (size_t m = 0; m < COUNT; ++m) {
	  printf("\n[%02zu] values:\na is %d\nb is %f\nc is %d\nd is %lld",
           m, q->a, q->b, q->c, q->d);
	  printf("\n[%02zu] addresses:\na is %p\nb is %p\nc is %p\nd is %p",
           m, &q->a, &q->b, &q->c, &q->d);
    q++;
  }
  putchar('\n');

  v = p;
  for (size_t m = 0; m < COUNT; ++m) {
	  printf("\n[%02zu] values:\na is %d\nb is %f\nc is %d\nd is %lld",
           m, ((MYSTRUCT*)v)->a, ((MYSTRUCT*)v)->b,
              ((MYSTRUCT*)v)->c, ((MYSTRUCT*)v)->d);
	  printf("\n[%02zu] addresses:\na is %p\nb is %p\nc is %p\nd is %p",
           m, &((MYSTRUCT*)v)->a, &((MYSTRUCT*)v)->b,
              &((MYSTRUCT*)v)->c, &((MYSTRUCT*)v)->d);
    v++;
  }
  putchar('\n');

  free(p);

	return 0;
}
