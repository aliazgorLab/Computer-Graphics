
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    int x = 0;
    int y = r;
    int p = 3 - 2*r;

    glBegin(GL_POINTS);

    while (x <= y)
    {
        plotPoints(x, y);

        if (p < 0)
        {
            p = p + 4*x + 6;
        }
        else
        {
            p = p + 4*(x - y) + 10;
            y--;
        }

        x++;
    }

    glEnd();
    glFlush();
}
