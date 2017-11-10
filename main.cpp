#include "Displays.h"

using namespace std;

void inicializar(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}


void escena(int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-width, width, -height, height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    bool ver = true;
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (2*width, 2*height);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Mi ventana de OpenGL");
    inicializar ();
    do{
        int op;
        cout << "\t1)Print Poligons\n\t2)Print Arc\n\t3)Print Cuadratic Prisma\n\t4)Triangle Prisma" << endl;
        cout << endl << "\tOption:"; cin >> op;
        if (op==1) {
            glutKeyboardFunc(keyboard_prismas);
            glutDisplayFunc(display_poligon);
            glutReshapeFunc(escena);
            glutMainLoop();
        }
        if (op==2) {
            glutKeyboardFunc(keyboard_arc);
            glutDisplayFunc(display_arc);
            glutReshapeFunc(escena);
            glutMainLoop();
        }
        if (op==3) {
            glutKeyboardFunc(keyboard_prisma);
            glutDisplayFunc(display_prisma);
            glutReshapeFunc(escena);
            glutMainLoop();
        }
        
        else ver = false;
    }while(ver);
    return 0;
}

