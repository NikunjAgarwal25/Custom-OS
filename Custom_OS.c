//Program for custom OS

#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int screenHeight= 600, screenWidth = 800;
char command[50];
char name[20];


void
init ()
{
  	glClearColor (1.0f, 1.0f, 1.0f, 0.0f);
  	glColor3f (1, 1, 0);
  	glPointSize (25.0f);
  	glLineWidth(5);
  	glMatrixMode (GL_PROJECTION);
  	glLoadIdentity ();
	gluOrtho2D (0, 800, 0, 600);
}


void
delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

void
menu()
{
	printf("\n--------------------------------------------------------------------------------\n");
	printf("\t\t\t\tWelcome to My-OS\n");
	printf("--------------------------------------------------------------------------------\n");
	delay(2000);
	printf("\nAvalaible commands: ");
	printf("\n1. L - ls");
	printf("\n2. P - pwd, poweroff");
	printf("\n3. M - mkdir, man");
	printf("\n4. R - rm, rmdir, reboot");
	printf("\n5. T - touch");
	
	printf("\n\nEnter the key for executing a command\n");
	delay(2000);
		
}

void
MyDisplay ()
{
    glClear( GL_COLOR_BUFFER_BIT );
 
    glBegin( GL_LINES );

        //-
        glColor3ub(0,0,0);
        glVertex2i(390,300);
        glVertex2i(410,300);
        
        //N
        glColor3ub(0,0,0);
        glVertex2i(180,250);
        glVertex2i(180,350);
        
        glColor3ub(0,0,0);
        glVertex2i(180,350);
        glVertex2i(250,250);
        
        glColor3ub(0,0,0);
        glVertex2i(250,250);
        glVertex2i(250,350);
        
        //G
        glColor3ub(0,0,0);
        glVertex2i(305,300);
        glVertex2i(340,300);
        
        glColor3ub(0,0,0);
        glVertex2i(280,250);
        glVertex2i(280,350);
        
        glColor3ub(0,0,0);
        glVertex2i(280,250);
        glVertex2i(340,250);
        
        glColor3ub(0,0,0);
        glVertex2i(280,350);
        glVertex2i(340,350);
        
        glColor3ub(0,0,0);
        glVertex2i(340,250);
        glVertex2i(340,300);
        
        //O
        glColor3ub(0,0,0);
        glVertex2i(460,250);
        glVertex2i(460,350);
        
        glColor3ub(0,0,0);
        glVertex2i(530,250);
        glVertex2i(530,350);
        
        glColor3ub(0,0,0);
        glVertex2i(460,250);
        glVertex2i(530,250);
        
        glColor3ub(0,0,0);
        glVertex2i(460,350);
        glVertex2i(530,350);
        
        //S
        glColor3ub(0,0,0);
        glVertex2i(560,300);
        glVertex2i(610,300);
        
        glColor3ub(0,0,0);
        glVertex2i(560,250);
        glVertex2i(610,250);
        
        glColor3ub(0,0,0);
        glVertex2i(560,350);
        glVertex2i(610,350);
        
        glColor3ub(0,0,0);
        glVertex2i(560,300);
        glVertex2i(560,350);
        
        glColor3ub(0,0,0);
        glVertex2i(610,250);
        glVertex2i(610,300);
        
        
        //box
        glColor3ub(0,0,0);
        glVertex2i(20,580);
        glVertex2i(20,20);
        
        glColor3ub(0,0,0);
        glVertex2i(20,20);
        glVertex2i(780,20);
        
        glColor3ub(0,0,0);
        glVertex2i(20,580);
        glVertex2i(780,580);
        
        glColor3ub(0,0,0);
        glVertex2i(780,20);
        glVertex2i(780,580);
        
    glEnd();

    glFlush();
}

void execute_ls()
{
    printf("\nls loading...");
    printf ("\nCurrent Files / Folders in Working Directory are ...\n");
    delay(1000);
    system ("ls");  
}

char confirmation()
{
	char input;
     printf ("\nEnter Y to proceed and N to abort current command: ");
     scanf (" %c", &input);
     return input;
}


void
keyboard (unsigned char key, int x, int y)
{
  	if (key == 'l' || key == 'L')
  	{
  		execute_ls();
  		printf("\n--------------------------------------------------------------------------------\n");
    	}
    	
  	if (key == 'p' || key == 'P')
  	{
  	     printf("\nMultiple command exist starting from %c\n",key);

     	printf("\nEnter Command to Execute: ");
     	scanf(" %s",command);
  	     
      	if (strcmp(command,"pwd")==0)
      	{    	
	  		printf("loading...");
	  	     printf ("\nCurrent Path ...\n");
	  	     delay(1000);
	  	     system ("pwd");
	  	     printf("\n--------------------------------------------------------------------------------\n");
	  	}
	  	
	  	else if (strcmp(command,"poweroff")==0)
	  	{
	  		if (confirmation() == 'Y' || confirmation() == 'y')
	 		{
	 			printf ("\nPoweroff ...\n");
	 			delay(2000);
	 			system ("poweroff");
	 		}
	  	}
     }
 		
	if (key == 'm' || key == 'M')
 	{
 		printf("\nMultiple command exist starting from %c\n",key);

     	printf("\nEnter Command to Execute: ");
     	scanf(" %s",command);
     	
     	if (strcmp(command,"mkdir")==0)
     	{
			printf("\nEnter the directory name: ");
			scanf(" %s",name);
			strcat(command," ");
			strcat(command,name);
			system(command);
			printf("\ndirectory %s created.",name);
			execute_ls();
			printf("\n--------------------------------------------------------------------------------\n");
		}
		
		else if (strcmp(command,"man")==0)
		{
			printf("\nEnter the command name to see man pages: ");
			scanf(" %s",name);
			strcat(command," ");
			strcat(command,name);
			system(command);
			printf("\n--------------------------------------------------------------------------------\n");
		}
			
     }
      
     if( key == 'r' || key == 'R')
     {
      	printf("\nMultiple command exist starting from 'r'\n");

      	char command[100];
      	printf("\nEnter Command to Execute: ");
      	scanf(" %s",command);

          if( strcmp(command,"rm") == 0 )
          {
	          execute_ls();

	          printf("\nEnter File Name to Delete: ");
	          scanf(" %s",name);
			strcat(command," ");
	          strcat(command,name);
	
	          system(command);
	          printf("\nFile %s Deleted\n",name);

          	execute_ls();
          	printf("\n--------------------------------------------------------------------------------\n");
          }
          
          else if( strcmp(command,"rmdir") == 0 )
          {
	          execute_ls();

	          //char name[20];

	          printf("\nEnter Directory Name to Delete: ");
	          scanf(" %s",name);
			strcat(command," ");
	          strcat(command,name);
	
	          system(command);
	          printf("\nDirectory %s Deleted\n",name);

          	execute_ls();
          	printf("\n--------------------------------------------------------------------------------\n");
          }
          
          else if( strcmp(command,"reboot") == 0)
          {
        		if( confirmation() == 'Y' || confirmation() == 'y' )
        		{
            		printf("\nrebooting ...\n");
            		delay(2000);
            		system("reboot");
        		} 
        	}
     }
        	
     if (key == 't' || key == 'T')
	{	
	  	//char name[20];
	 	printf("\nEnter the file name: ");
		scanf(" %s",name);
		strcat(command,"touch ");
		strcat(command,name);
		system(command);
		printf("\nfile %s created.\n",name);
		delay(2000);
		execute_ls();
		printf("\n--------------------------------------------------------------------------------\n");
	}
     
}


void
processSpecialKeys (int key, int x, int y)
{
  	printf ("\nSpecial Keyboard Key: %d", key);
}

void
main (int argc, char **argv)
{
	menu();
  	glutInit (&argc, argv);
  	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  	glutInitWindowSize (screenWidth, screenHeight);
  	glutInitWindowPosition (900, 0);
  	glutCreateWindow ("NG-OS");
  	init ();
  	glutDisplayFunc (MyDisplay);
  	glutKeyboardFunc (keyboard);
  	glutSpecialFunc (processSpecialKeys);
 	glutMainLoop ();
}
