
#include <bits/stdc++.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

int shape;

float tx = 0, ty = 0;
float sx = 1, sy = 1;
float angle = 0;
int fx = 1, fy = 1;
float shx = 0, shy = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    glTranslatef(tx, ty, 0);
    glRotatef(angle, 0, 0, 1);
    glScalef(sx * fx, sy * fy, 1);

    // Shearing matrix
    float matrix[] = {
        1, shy, 0, 0,
        shx, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };

    glMultMatrixf(matrix);

    glColor3f(1, 1, 1);

    if (shape == 1)
    {
        // Circle
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 360; i++)
        {
            float a = i * 3.14159 / 180;
            glVertex2f(60 * cos(a), 60 * sin(a));
        }
        glEnd();
    }
    else if (shape == 2)
    {
        // Triangle
        glBegin(GL_LINE_LOOP);
        glVertex2i(0, 70);
        glVertex2i(-60, -40);
        glVertex2i(60, -40);
        glEnd();
    }
    else if (shape == 3)
    {
        // Rectangle
        glBegin(GL_LINE_LOOP);
        glVertex2i(-70, -40);
        glVertex2i(70, -40);
        glVertex2i(70, 40);
        glVertex2i(-70, 40);
        glEnd();
    }
    else if (shape == 4)
    {
        // Polygon
        glBegin(GL_LINE_LOOP);
        glVertex2i(-50, 0);
        glVertex2i(-25, 50);
        glVertex2i(25, 50);
        glVertex2i(60, 0);
        glVertex2i(25, -50);
        glVertex2i(-25, -50);
        glEnd();
    }

    glPopMatrix();
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 't': tx += 20; break;
        case 's': sx *= 1.2; sy *= 1.2; break;
        case 'r': angle += 15; break;
        case 'f': fx *= -1; break;

        case 'h': shx += 0.2; break; // X-shear
        case 'v': shy += 0.2; break; // Y-shear

        case '0':
            tx = ty = 0;
            sx = sy = 1;
            angle = 0;
            fx = fy = 1;
            shx = shy = 0;
            break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    cout << "Select Shape:\n";
    cout << "1. Circle\n";
    cout << "2. Triangle\n";
    cout << "3. Rectangle\n";
    cout << "4. Polygon\n";
    cout << "Enter choice: ";
    cin >> shape;

    if (shape < 1 || shape > 4)
    {
        cout << "Invalid choice!";
        return 0;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D Transformations");

    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-250, 250, -250, 250);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
