#include <stdio.h>
#include <math.h>

int main(void)
{
    double x1 = 1.0;
    double y1 = 2.0;
    double x2 = 4.0;
    double y2 = 6.0;

    double distance;

    distance = sqrt((x2 - x1) * (x2 - x1) +
                    (y2 - y1) * (y2 - y1));

    printf("La distance entre les points (%.2f, %.2f) et (%.2f, %.2f) est : %.2f\n",
           x1, y1, x2, y2, distance);

    return 0;
}