#include <GL/freeglut.h>
#include <iostream>
#include "actor.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

//=================================================================================================
// CALLBACKS
//=================================================================================================

//-----------------------------------------------------------------------------
// CALLBACK DOCUMENTATION
// https://www.opengl.org/resources/libraries/glut/spec3/node45.html
// http://freeglut.sourceforge.net/docs/api.php#WindowCallback
//-----------------------------------------------------------------------------

void idle_func()
{
	//uncomment below to repeatedly draw new frames
	//glutPostRedisplay();
}

void reshape_func( int width, int height )
{
	glViewport( 0, 0, width, height );
	glutPostRedisplay();
}

void keyboard_func( unsigned char key, int x, int y )
{
	switch( key )
	{
		case 'w':
		{
			std::cout << "Up" << std::endl;
			break;
		}

		case 'a':
		{
			std::cout << "Left" << std::endl;
			break;
		}

		case 's':
		{
			std::cout << "Down" << std::endl;
			break;
		}

		case 'd':
		{
			std::cout << "Right" << std::endl;
			break;
		}

		// Exit on escape key press
		case '\x1B':
		{
			exit( EXIT_SUCCESS );
			break;
		}
	}

	glutPostRedisplay();
}

void key_released( unsigned char key, int x, int y )
{
}

void key_special_pressed( int key, int x, int y )
{
}	

void key_special_released( int key, int x, int y )
{
}

void mouse_func( int button, int state, int x, int y )
{
}

void passive_motion_func( int x, int y )
{
}

void active_motion_func( int x, int y )
{
}

//=================================================================================================
// RENDERING
//=================================================================================================

void display_func( void )
{
	// Maybe have display functions in other header files for each seperate case, like enemies and the player, then call them here

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	actor test = actor();
	test.drawActor();

	/*
	glColor3f( 1.0f, 1.0f, 1.0f );
	glBegin( GL_TRIANGLES );
		glVertex2f( 0.1f, 0.1f );
		glVertex2f( 0.3f, 0.1f );
		glVertex2f( 0.1f, 0.3f );
	glEnd();
	
	glBegin( GL_TRIANGLES );
		glVertex2f( 0.1f, 0.3f );
		glVertex2f( 0.3f, 0.1f );
		glVertex2f( 0.3f, 0.3f );
	glEnd();
	*/

	// Testing stbi image functionality for loading player sprite
	int width, height, color;
	unsigned char* imgLoad = stbi_load("PlayerShip1.png", &width, &height, &color, 0);




	glutSwapBuffers();
}

//=================================================================================================
// INIT
//=================================================================================================

void init( void )
{
	// Print some info
	std::cout << "Vendor:         " << glGetString( GL_VENDOR   ) << "\n";
	std::cout << "Renderer:       " << glGetString( GL_RENDERER ) << "\n";
	std::cout << "OpenGL Version: " << glGetString( GL_VERSION  ) << "\n\n";

	// Set the background color
	glClearColor( 0.4f, 0.4f, 0.4f, 0.0f );

	std::cout << "Finished initializing...\n\n";
}

//=================================================================================================
// MAIN
//=================================================================================================

int main( int argc, char** argv )
{
	glutInit( &argc, argv );

	glutInitWindowPosition( (1920 - 900)/2 , (1080 - 900)/2 );
	glutInitWindowSize( 900, 900 );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );

	glutCreateWindow( "Basic OpenGL Example" );

	glutDisplayFunc( display_func );
	glutIdleFunc( idle_func );
	glutReshapeFunc( reshape_func );
	glutKeyboardFunc( keyboard_func );
	glutKeyboardUpFunc( key_released );
	glutSpecialFunc( key_special_pressed );
	glutSpecialUpFunc( key_special_released );
	glutMouseFunc( mouse_func );
	glutMotionFunc( active_motion_func );
	glutPassiveMotionFunc( passive_motion_func );

	init();

	glutMainLoop();

	return EXIT_SUCCESS;
}
