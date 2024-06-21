#include <iostream>
#include <windows.h> // Load W32 window, console window.
#include <gl/glut.h> // OpenGL toolkit
#include <math.h>
#include "object.h"

using namespace std; // There is no need to specific the std prefix for I/O.


Object spritetxt = Object();
Object spritbackgrd = Object();
string txt;

void render(){ // Render function definition
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // RGBA
	
	// Canvas settings
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1280, 0, 862); // Set canvas to 1820x862 pixels.

	
	glClear(GL_COLOR_BUFFER_BIT); // Load frame buffer.
	
	//background
	spritbackgrd.drawRect(0, 0, 1280, 862);
	
	// drawing the left side of the glasses
	
	
	//connecting the glasses from top with top bar
	glLineWidth(13);
	glPushMatrix;
	glBegin(GL_LINES);
		
		glColor3f(0.75294117647f, 0.75294117647f, 0.75294117647f);
		
	    glVertex2f(326, 850-305);
	    glVertex2f(640, 850-305);
	    
	glEnd();
	glPopMatrix;
	
	//shadow of the glasses
	
	glLineWidth(7);
	glPushMatrix;
	glBegin(GL_LINES);
		
		glColor3f(1.0f, 1.0f, 1.0f);//white
	    glVertex2f(129, 850-706);
	    glColor3f(0.0f, 0.0f, 0.0f); //black
	    glVertex2f(245, 850-706);
	    
	    glVertex2f(245, 850-706);
	    glColor3f(1.0f, 1.0f, 1.0f);//white
	    glVertex2f(461, 850-706);
	    
	glEnd();
	glPopMatrix;
	
	// connecting with glasses bridge part
	glPushMatrix;
	glBegin(GL_POLYGON);
	
	//start colring with beige
		glColor3f(0.75294117647f, 0.75294117647f, 0.75294117647f);
		
		glVertex2i(640,850-395); glVertex2i(640,850-418);
		glVertex2i(589,850-418); glVertex2i(586,850-419);
		glVertex2i(582,850-444); glVertex2i(572,850-455);
		glVertex2i(567,850-407); glVertex2i(577,850-401);
		glVertex2i(593,850-395);
	
	
	glEnd();
	glPopMatrix;

	
	//glasses nose pads
	glPushMatrix; 
	glBegin(GL_POLYGON);
		
		//start coloring with black color
		
		glColor3f(0.0f, 0.0f, 0.0f);
		
		glVertex2i(568,850-469); glVertex2i(561,850-475);
		glVertex2i(553,850-498); glVertex2i(541,850-527);
		glVertex2i(529,850-555); 
		
		
		//start coloring with goldish for shade
		
		glVertex2i(520,850-578);
		glVertex2i(533,850-566);
		glColor3f(0.95686274509f, 0.78039215686f, 0.61960784313f); 
		glVertex2i(544,850-553);
		glVertex2i(561,850-528); 
		glVertex2i(570,850-510);
		glVertex2i(576,850-496); glVertex2i(578,850-485);
		glVertex2i(575,850-475); glVertex2i(568,850-469);
		
		
	glEnd();
	glPopMatrix;
	
	
	//drawing the end piece that connects with temples
	glPushMatrix;
	glBegin(GL_POLYGON);
		
		//start coloring with beige
		glColor3f(0.75294117647f, 0.75294117647f, 0.75294117647f);
		
		glVertex2i(93,850-455); glVertex2i(26,850-455);
		glVertex2i(26,850-431); glVertex2i(53,850-421);
		glVertex2i(88,850-419); glVertex2i(91,850-455);
		glVertex2i(51,850-431); glVertex2i(94,850-431);
		glVertex2i(93,850-455);
	
	glEnd();
	glPopMatrix;
	
	
	//drawing the outer darkish frame
	
	glPushMatrix;
	glBegin(GL_POLYGON);
		
		glColor3f(0.219f, 0.203f, 0.270f); // outer frame darkish purple
		
		//top of the outer frame
		glVertex2i(324,850-309); glVertex2i(300,850-310);
		glVertex2i(249,850-310); glVertex2i(206,850-312);
		glVertex2i(168,850-321); glVertex2i(138,850-333);
		
		//topleft corner and left of the outer frame
		glVertex2i(117,850-349); glVertex2i(105,850-364);
		glVertex2i(95,850-386); glVertex2i(88,850-416);
		glVertex2i(88,850-415); glVertex2i(85,850-448);
		glVertex2i(88,850-504); glVertex2i(96,850-555);
		
		
		//bottom left corner outer frame
		glVertex2i(112,850-615); glVertex2i(122,850-643);
		glVertex2i(135,850-661);
		glVertex2i(151,850-676); glVertex2i(193,850-693);
		

		
		//bottom outer frame
		glVertex2i(258,850-703); glVertex2i(340,850-703);
		
		//bottom right corner and right outer frame
		glVertex2i(403,850-698); glVertex2i(429,850-690);
		glVertex2i(448,850-679); glVertex2i(474,850-652);
		
		//top right corner outer frame
		glVertex2i(529,850-570); glVertex2i(558,850-504);
		glVertex2i(572,850-450); glVertex2i(566,850-392);
		glVertex2i(543,850-352); glVertex2i(498,850-328);
		
		//top outer frame ( connecting to origin
		glVertex2i(408,850-313); glVertex2i(367,850-313);
		glVertex2i(324,850-309);
		
	glEnd();
	glPopMatrix;
		
		
	// inside glass 
	
	glPushMatrix;	
	glBegin(GL_POLYGON);
		
		//start coloring with blue
		glColor3f(0.59607843137f, 0.78039215686f, 0.85098039215f); // outer frame darkish 
		
		//top of glass
		glVertex2i(354,850-339); glVertex2i(267,850-339);
		glVertex2i(226,850-339);glVertex2i(176,850-346);
		
		//left corner of glass
		glVertex2i(135,850-369); glVertex2i(116,850-426);
		glVertex2i(114,850-493); glVertex2i(127,850-568);
		glVertex2i(162,850-644); glVertex2i(190,850-661);
		
		//change to lighter blue v1.0
		glColor3f(0.66666666666f, 0.92549019607f, 0.98823529411f);
		//bottom of glass
		glVertex2i(246,850-674); glVertex2i(302,850-674);
		glVertex2i(351,850-678); glVertex2i(394,850-672);
		
		//bottom right corner of glass
		glVertex2i(426,850-659); glVertex2i(456,850-628);
		
		
		//change to lighter blue v2.0 to make the polygon color gradient( blue/lightblue)
		glColor3f(0.82745098039f, 0.95686274509f, 1.0f);
		
		//right of glass
		glVertex2i(486,850-579); glVertex2i(520,850-509);
		glVertex2i(542,850-444); glVertex2i(543,850-420);
		
		
		//top right corner of glass
		glVertex2i(534,850-394); glVertex2i(521,850-372);
		
		//top of glass connecting
		glVertex2i(471,850-347); glVertex2i(354,850-339);
		
		
		
		
	glEnd();
	glPopMatrix;
	
	
	//drawing the temples
	
	//first triangle
	glPushMatrix;
	glBegin(GL_TRIANGLES);
		
		//start coloring with beige
		glColor3f(0.65882352941f, 0.78823529411f, 0.83921568627f);
		
		glVertex2i(119,850-415); 
		glVertex2i(173,850-403);
		glVertex2i(115,850-458); 
		
	glEnd();
	glPopMatrix;
	
	//draw the rest as polygon
	glPushMatrix;
	glBegin(GL_POLYGON);
		
		//start coloring with beige
		glColor3f(0.65882352941f, 0.78823529411f, 0.83921568627f);
		
		glVertex2i(170,850-402); glVertex2i(274,850-492);
		glVertex2i(296,850-515); glVertex2i(315,850-543);
		glVertex2i(321,850-575); glVertex2i(319,850-592);
		glVertex2i(300,850-604); glVertex2i(316,850-580);
		glVertex2i(309,850-562); glVertex2i(213,850-446);
		glVertex2i(160,850-416); glVertex2i(170,850-402);
		
		
	glEnd();
	glPopMatrix;
	
	//signal lines
	//line1
	glLineWidth(7);
	glPushMatrix;
	glBegin(GL_LINES);
		
		glColor3f(0.0f, 0.0f, 0.0f);
		
	    glVertex2f(470, 850-380); glVertex2f(470, 850-373);
	    
	glEnd();
	glPopMatrix;
	
	//line2
	glPushMatrix;
	glBegin(GL_LINES);
		
		glColor3f(0.0f, 0.0f, 0.0f);
		
	    glVertex2f(480, 850-380); glVertex2f(480, 850-370);
	    
	glEnd();
	glPopMatrix;
	
	//line3
	glPushMatrix;
	glBegin(GL_LINES);
		
		glColor3f(0.0f, 0.0f, 0.0f);
		
	    glVertex2f(490, 850-380); glVertex2f(490, 850-367);
	    
	glEnd();
	glPopMatrix;
	
	//battery shape
	//black line from bottom 
	
	glLineWidth(8);
	glPushMatrix;
	glBegin(GL_LINES);
		
		glColor3f(0.0f, 0.0f, 0.0f);
		
	    glVertex2f(450, 850-380); glVertex2f(450, 850-368);
	    
	glEnd();
	glPopMatrix;
	
	//white line on top  
	
	glPushMatrix;
	glBegin(GL_LINES);
		
		glColor3f(1.0f, 1.0f, 1.0f);
		
	    glVertex2f(450, 850-368); glVertex2f(450, 850-364);
	    
	glEnd();
	glPopMatrix;
	
	//black line for the top of battery 
	
	glLineWidth(4);
	glPushMatrix;
	glBegin(GL_LINES);
		
		glColor3f(0.0f, 0.0f, 0.0f);
		
	    glVertex2f(450, 850-364); glVertex2f(450, 850-360);
	    
	glEnd();
	glPopMatrix;
	
	//battery txt in the side:
	glColor3f(0.0f, 0.0f, 0.0f);
	txt = "Battery";
	spritetxt.drawText(txt.data(), txt.size(), 380, 850-380, GLUT_BITMAP_9_BY_15);
	
	//draw record icon: filled circle
	
	//record txt in the side:
	glColor3f(0.0f, 0.0f, 0.0f);
	txt = "Rec";
	spritetxt.drawText(txt.data(), txt.size(), 150, 850-373, GLUT_BITMAP_9_BY_15);	
	
	//dot inside
	float theta;
	glColor3f(0.0f, 0.0f, 0.0f);
	glPushMatrix;
	glBegin(GL_POLYGON);
		for(int i=0; i<360;i++){
			theta = i*3.142/180;
			glVertex2f(182+4*cos(theta),850-370+4*sin(theta));
			
		}
	glEnd();
	glPopMatrix;
	
	//white rectangle
	
	
	
	//draw focus rectangle
    
    //8 pieces of line
    
    glLineWidth(2);
    
    //line 1: top left
	glPushMatrix;
	glBegin(GL_LINES);

		glColor3f(0.0f, 0.0f, 0.0f); //black
	    glVertex2i(220,850-420); glVertex2i(220,850-453); 
	
	glEnd();
	glPopMatrix;
	
	//line 2: top left
	glPushMatrix;
	glBegin(GL_LINES);

		glColor3f(0.0f, 0.0f, 0.0f); //black
	    glVertex2i(220,850-420); glVertex2i(250,850-420);
	
	glEnd();
	glPopMatrix;
	
	//line 3: bottom left
	glPushMatrix;
	glBegin(GL_LINES);

		glColor3f(0.0f, 0.0f, 0.0f); //black
	    glVertex2i(220,850-550); glVertex2i(220,850-583);
	
	glEnd();
	glPopMatrix;
	
	//line 4: bottom left 
	
	glPushMatrix;
	glBegin(GL_LINES);

		glColor3f(0.0f, 0.0f, 0.0f); //black
	    glVertex2i(220,850-583); glVertex2i(253,850-583);
	
	glEnd();
	glPopMatrix;
	
	//mirror the left side to finish the focus rectangle
	glTranslatef( 320, 0.0f , 0.0f );
	glScalef( -1.0f, 1.0f, 1.0f );
	glTranslatef( -320, 0.0f , 0.0f ); 
	
	//line 1: top left
	glPushMatrix;
	glBegin(GL_LINES);

		glColor3f(0.0f, 0.0f, 0.0f); //black
	    glVertex2i(220,850-420); glVertex2i(220,850-453); 
	
	glEnd();
	glPopMatrix;
	
	//line 2: top left
	glPushMatrix;
	glBegin(GL_LINES);

		glColor3f(0.0f, 0.0f, 0.0f); //black
	    glVertex2i(220,850-420); glVertex2i(250,850-420);
	
	glEnd();
	glPopMatrix;
	
	//line 3: bottom left
	glPushMatrix;
	glBegin(GL_LINES);

		glColor3f(0.0f, 0.0f, 0.0f); //black
	    glVertex2i(220,850-550); glVertex2i(220,850-583);
	
	glEnd();
	glPopMatrix;
	
	//line 4: bottom left 
	
	glPushMatrix;
	glBegin(GL_LINES);

		glColor3f(0.0f, 0.0f, 0.0f); //black
	    glVertex2i(220,850-583); glVertex2i(253,850-583);
	
	glEnd();
	glPopMatrix;
	

	glLoadIdentity(); // reset identity		
			
	//glVertex2i(,850-); glVertex2i(,850-);	

	
	//mirroring the left side of the glasses to the right side using the vertical axis 
	
	// drawing the right side of the glasses
	
	glTranslatef( 640, 0.0f , 0.0f );
	glScalef( -1.0f, 1.0f, 1.0f );
	glTranslatef( -640, 0.0f , 0.0f );  
	
	
	//display time text on the right glasses
	
	//connecting the glasses from top with top bar
	glLineWidth(13);
	glPushMatrix;
	glBegin(GL_LINES);
		
		glColor3f(0.75294117647f, 0.75294117647f, 0.75294117647f);
		
	    glVertex2f(326, 850-305);
	    glVertex2f(640, 850-305);
	    
	glEnd();
	glPopMatrix;
	//shadow of the glasses
	
	glLineWidth(7);
	glPushMatrix;
	glBegin(GL_LINES);
		
		glColor3f(1.0f, 1.0f, 1.0f);//white
	    glVertex2f(129, 850-706);
	    glColor3f(0.0f, 0.0f, 0.0f); //black
	    glVertex2f(245, 850-706);
	    
	    glVertex2f(245, 850-706);
	    glColor3f(1.0f, 1.0f, 1.0f);//white
	    glVertex2f(461, 850-706);
	    
	glEnd();
	glPopMatrix;
	
	// connecting with glasses bridge part
	glPushMatrix;
	glBegin(GL_POLYGON);
	
	//start colring with beige
		glColor3f(0.75294117647f, 0.75294117647f, 0.75294117647f);
		
		glVertex2i(640,850-395); glVertex2i(640,850-418);
		glVertex2i(589,850-418); glVertex2i(586,850-419);
		glVertex2i(582,850-444); glVertex2i(572,850-455);
		glVertex2i(567,850-407); glVertex2i(577,850-401);
		glVertex2i(593,850-395);
	
	
	glEnd();
	glPopMatrix;

	
	//glasses nose pads
	glPushMatrix; 
	glBegin(GL_POLYGON);
		
		//start coloring with black color
		
		glColor3f(0.0f, 0.0f, 0.0f);
		
		glVertex2i(568,850-469); glVertex2i(561,850-475);
		glVertex2i(553,850-498); glVertex2i(541,850-527);
		glVertex2i(529,850-555); 
		
		
		//start coloring with goldish for shade
		
		glVertex2i(520,850-578);
		glVertex2i(533,850-566);
		glColor3f(0.95686274509f, 0.78039215686f, 0.61960784313f); 
		glVertex2i(544,850-553);
		glVertex2i(561,850-528); 
		glVertex2i(570,850-510);
		glVertex2i(576,850-496); glVertex2i(578,850-485);
		glVertex2i(575,850-475); glVertex2i(568,850-469);
		
		
	glEnd();
	glPopMatrix;
	
	
	//drawing the end piece that connects with temples
	glPushMatrix;
	glBegin(GL_POLYGON);
		
		//start coloring with beige
		glColor3f(0.75294117647f, 0.75294117647f, 0.75294117647f);
		
		glVertex2i(93,850-455); glVertex2i(26,850-455);
		glVertex2i(26,850-431); glVertex2i(53,850-421);
		glVertex2i(88,850-419); glVertex2i(91,850-455);
		glVertex2i(51,850-431); glVertex2i(94,850-431);
		glVertex2i(93,850-455);
	
	glEnd();
	glPopMatrix;
	
	
	//drawing the outer darkish frame
	
	glPushMatrix;
	glBegin(GL_POLYGON);
		
		glColor3f(0.219f, 0.203f, 0.270f); // outer frame darkish purple
		
		//top of the outer frame
		glVertex2i(324,850-309); glVertex2i(300,850-310);
		glVertex2i(249,850-310); glVertex2i(206,850-312);
		glVertex2i(168,850-321); glVertex2i(138,850-333);
		
		//topleft corner and left of the outer frame
		glVertex2i(117,850-349); glVertex2i(105,850-364);
		glVertex2i(95,850-386); glVertex2i(88,850-416);
		glVertex2i(88,850-415); glVertex2i(85,850-448);
		glVertex2i(88,850-504); glVertex2i(96,850-555);
		
		
		//bottom left corner outer frame
		glVertex2i(112,850-615); glVertex2i(122,850-643);
		glVertex2i(135,850-661);
		glVertex2i(151,850-676); glVertex2i(193,850-693);
		

		
		//bottom outer frame
		glVertex2i(258,850-703); glVertex2i(340,850-703);
		
		//bottom right corner and right outer frame
		glVertex2i(403,850-698); glVertex2i(429,850-690);
		glVertex2i(448,850-679); glVertex2i(474,850-652);
		
		//top right corner outer frame
		glVertex2i(529,850-570); glVertex2i(558,850-504);
		glVertex2i(572,850-450); glVertex2i(566,850-392);
		glVertex2i(543,850-352); glVertex2i(498,850-328);
		
		//top outer frame ( connecting to origin
		glVertex2i(408,850-313); glVertex2i(367,850-313);
		glVertex2i(324,850-309);
		
	glEnd();
	glPopMatrix;
		
		
	// inside glass 
	
	glPushMatrix;	
	glBegin(GL_POLYGON);
		
		//start coloring with blue
		glColor3f(0.59607843137f, 0.78039215686f, 0.85098039215f); // outer frame darkish 
		
		//top of glass
		glVertex2i(354,850-339); glVertex2i(267,850-339);
		glVertex2i(226,850-339);glVertex2i(176,850-346);
		
		//left corner of glass
		glVertex2i(135,850-369); glVertex2i(116,850-426);
		glVertex2i(114,850-493); glVertex2i(127,850-568);
		glVertex2i(162,850-644); glVertex2i(190,850-661);
		
		//change to lighter blue v1.0
		glColor3f(0.66666666666f, 0.92549019607f, 0.98823529411f);
		//bottom of glass
		glVertex2i(246,850-674); glVertex2i(302,850-674);
		glVertex2i(351,850-678); glVertex2i(394,850-672);
		
		//bottom right corner of glass
		glVertex2i(426,850-659); glVertex2i(456,850-628);
		
		
		//change to lighter blue v2.0 to make the polygon color gradient( blue/lightblue)
		glColor3f(0.82745098039f, 0.95686274509f, 1.0f);
		
		//right of glass
		glVertex2i(486,850-579); glVertex2i(520,850-509);
		glVertex2i(542,850-444); glVertex2i(543,850-420);
		
		
		//top right corner of glass
		glVertex2i(534,850-394); glVertex2i(521,850-372);
		
		//top of glass connecting
		glVertex2i(471,850-347); glVertex2i(354,850-339);
		
		
		
		
	glEnd();
	glPopMatrix;
	
	
	//drawing the temples
	
	//first triangle
	glPushMatrix;
	glBegin(GL_TRIANGLES);
		
		//start coloring with beige
		glColor3f(0.65882352941f, 0.78823529411f, 0.83921568627f);
		
		glVertex2i(119,850-415); 
		glVertex2i(173,850-403);
		glVertex2i(115,850-458); 
		
	glEnd();
	glPopMatrix;
	
	//draw the rest as polygon
	glPushMatrix;
	glBegin(GL_POLYGON);
		
		//start coloring with beige
		glColor3f(0.65882352941f, 0.78823529411f, 0.83921568627f);
		
		glVertex2i(170,850-402); glVertex2i(274,850-492);
		glVertex2i(296,850-515); glVertex2i(315,850-543);
		glVertex2i(321,850-575); glVertex2i(319,850-592);
		glVertex2i(300,850-604); glVertex2i(316,850-580);
		glVertex2i(309,850-562); glVertex2i(213,850-446);
		glVertex2i(160,850-416); glVertex2i(170,850-402);
		
		
	glEnd();
	glPopMatrix;
	
	glLoadIdentity();
	
	//display time text on the right glasses
	spritetxt.scale(20,20);
	glColor3f(0.0f, 0.0f, 0.0f);
	txt = "10:15 AM";
	spritetxt.drawText(txt.data(), txt.size(), 800, 850-373 , GLUT_BITMAP_TIMES_ROMAN_24);
	
	
	
	

	
	glutSwapBuffers();
	glFlush(); // Clear all GL executions.
	glFinish(); // Block until all GL executions are completed.
}

int main(){	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Single frame buffer 
												 // with RGB colours.
	glutInitWindowSize(1280, 862); // OpenGL window resolution.
	glutInitWindowPosition(50, 50); // Window position on the screen.
	glutCreateWindow("Edith Smart Glasses"); // OpenGL window title.
	glutDisplayFunc(render); // Load render function.
	glutMainLoop(); // Loop frame forever.
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	system("PAUSE"); // Press any key to stop the frame.
	return 0; // Exit the main thread of the program.
}




