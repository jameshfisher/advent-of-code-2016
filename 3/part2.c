/*

--- Day 3: Squares With Three Sides ---

Now that you can think clearly, you move deeper into the labyrinth of hallways
and office furniture that makes up this part of Easter Bunny HQ. This must be a
graphic design department; the walls are covered in specifications for
triangles.

Or are they?

The design document gives the side lengths of each triangle it describes, but...
5 10 25? Some of these aren't triangles. You can't help but mark the impossible
ones.

In a valid triangle, the sum of any two sides must be larger than the remaining
side. For example, the "triangle" given above is impossible, because 5 + 10 is
not larger than 25.

In your puzzle input, how many of the listed triangles are possible?

--- Part Two ---

Now that you've helpfully marked up their design documents, it occurs to you
that triangles are specified in groups of three vertically. Each set of three
numbers in a column specifies a triangle. Rows are unrelated.

For example, given the following specification, numbers with the same hundreds
digit would be part of the same triangle:

    101 301 501
    102 302 502
    103 303 503
    201 401 601
    202 402 602
    203 403 603

In your puzzle input, and instead reading by columns, how many of the listed
triangles are possible?
*/

#include <stdio.h>
#include <stdlib.h>

int gt(const void * a, const void * b)
{
  return *((int*) a) > *((int*) b);
}

int main(void)
{
  int possible = 0;

  int c1[3];
  int c2[3];
  int c3[3];

  while (
    scanf("%d %d %d", &c1[0], &c2[0], &c3[0]) == 3  &&
    scanf("%d %d %d", &c1[1], &c2[1], &c3[1]) == 3  &&
    scanf("%d %d %d", &c1[2], &c2[2], &c3[2]) == 3
  )
  {
    qsort(c1, 3, sizeof(int), &gt);
    qsort(c2, 3, sizeof(int), &gt);
    qsort(c3, 3, sizeof(int), &gt);

    if (c1[0] + c1[1] > c1[2]) { possible++; }
    if (c2[0] + c2[1] > c2[2]) { possible++; }
    if (c3[0] + c3[1] > c3[2]) { possible++; }
  }

  printf("The number of possible triangles is: %d\n", possible);

  return 0;
}
