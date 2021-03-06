// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

using namespace std;

void dibujarTriangulos(){
	glBegin(GL_TRIANGLES);
	glColor3f(0, 0.5, 0.5);
	glVertex3f(0, 1, 0);
	glVertex3f(-1, -1, 0);
	glVertex3f(1, -1, 0);

	glColor3f(0.1, 0.1, 0.1);
	glVertex3f(1, 1, 0);
	glVertex3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 1, 0);
	glVertex3f(0, 1, 0);
	glVertex3f(0, 0, 0);

	glEnd();
}

void dibujarPuntos() {
	glBegin(GL_POINTS);
	glColor3f(1, 1, 1);
	glVertex3f(0.5, 0.1, 0);
	glColor3f(0, 1, 0);
	glVertex3f(0.6, 0.1, 0);

	glEnd();
}

void dibujarLineas() {
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(0.5, 0, 0);
	glColor3f(0, 1, 0);
	glVertex3f(-0.7, -0.65, 0);
	glVertex3f(-0.7, -0.65, 0);
	glColor3f(0, 0, 1);
	glVertex3f(-0.85, 0.2, 0);

	glEnd();
}

void dibujarLineaContiua() {
	glBegin(GL_LINE_STRIP);
	glColor3f(1, 0, 0);
	glVertex3f(0.5, 0, 0);
	glColor3f(0, 1, 0);
	glVertex3f(-0.7, -0.65, 0);
	glColor3f(0, 0, 1);
	glVertex3f(-0.85, 0.2, 0);
	glEnd();
}

void dibujarTrianguloContinuo() {
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0, 1, 0);
	glVertex3f(-0.2, 0, 0);
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0.2, 0);
	glColor3f(1,0,0);
	glVertex3f(0.2, 0, 0);
	glVertex3f(0.2, 0.2, 0);
	glEnd();
}

void dibujar() {
	//dibujarTriangulos();
	//dibujarPuntos();
	//dibujarLineas();
	dibujarLineaContiua();
	dibujarTrianguloContinuo();
}

void actualizar() {

}

int main()
{
	//Declaramos apuntador de ventana
	GLFWwindow *window;

	//si no se pudo inicializar glfw terminamos ejecución
	if (!glfwInit())
		exit(EXIT_FAILURE);

	//si se pudo iniciar GLFW entonces inicializamos la ventana
	window = glfwCreateWindow(1024, 768, "Ventana", NULL, NULL);

	//si no podemos iniciar la ventana entonces terminamos la ejecución
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//establecemos el contexto
	glfwMakeContextCurrent(window);

	//UNa vez establecido el contexto activamos funciones modernas (CPU/GPU)
	glewExperimental = true;
	GLenum errorGlew = glewInit();

	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}

	const GLubyte *versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;


	//Cilco de dibijo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region de dibujo
		glViewport(0, 0, 1024, 768);
		//Esctablece el color de borrado
		glClearColor(0.25, 0, 0.3, 1);
		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar los buffers
		glfwSwapBuffers(window);
		//Reconocer si hay entradas
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

