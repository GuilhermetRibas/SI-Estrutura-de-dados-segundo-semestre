#include <stdio.h>

int dentro_ret(int x0, int y0, int x1, int y1, int x, int y)
{

    if (x >= x0 && x <= x1 && y >= y0 && y <= y1)
    {
        return 1;
    }
    return 0;
}
// 0 - inferior esuquerdo, 1 superior direito
int main()
{

    int x0 = 1;
    int y0 = 1;
    int x1 = 5;
    int y1 = 5;
    int x = 0;
    int y = 0;

    printf("%d", dentro_ret(x0, y0, x1, y1, x, y));
}