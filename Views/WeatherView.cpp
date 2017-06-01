//
// Created by andreimerfu on 27.05.2017.
//

#include "WeatherView.h"


#define MAX_PARTICLES 100000
/*#define WCX		640
#define WCY		480*/
#define RAIN	0
#define SNOW	1
#define	HAIL	2


float slowdown = 2.0;
float velocity = 0.0;
double zoom = -40.0;
float pan = 0.0;
float tilt = 0.0;
float hailsize = 0.1;

int loop;
int fall;

//floor colors
double r = 0.0;
double g = 1.0;
double b = 0.0;
double ground_points[21][21][3];
double ground_colors[21][21][4];
double accum = -10.0;

typedef struct {
    // Life
    bool alive;	// is the particle alive?
    double life;	// particle lifespan
    double fade; // decay
    // color
    double red;
    double green;
    double blue;
    // Position/direction
    double xpos;
    double ypos;
    double zpos;
    // Velocity/Direction, only goes down in y dir
    double vel;
    // Gravity
    double gravity;
}particles;

particles par_sys[MAX_PARTICLES];



void initParticles(int i) {
    par_sys[i].alive = true;
    par_sys[i].life = 10.0;
    par_sys[i].fade = float(rand()%100)/1000.0f+0.003f;

    par_sys[i].xpos = (float) (rand() % 300) - 100;
    par_sys[i].ypos = 101.0;
    par_sys[i].zpos = (float) (rand() % 300) - 100;


    par_sys[i].red = 0.5;
    par_sys[i].green = 0.5;
    par_sys[i].blue = 1.0;

    par_sys[i].vel = velocity;
    par_sys[i].gravity = -0.8;//-0.8;

}


void initWeather(void){
    int x, z;

    glShadeModel(GL_SMOOTH);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);

    // Ground Verticies
    // Ground Colors
    for (z = 0; z < 21; z++) {
        for (x = 0; x < 21; x++) {
            ground_points[x][z][0] = x - 10.0;
            ground_points[x][z][1] = accum;
            ground_points[x][z][2] = z - 10.0;

            ground_colors[z][x][0] = r; // red value
            ground_colors[z][x][1] = g; // green value
            ground_colors[z][x][2] = b; // blue value
            ground_colors[z][x][3] = 0.0; // acummulation factor
        }
    }

    // Initialize particles
    for (loop = 0; loop < MAX_PARTICLES; loop++) {
        initParticles(loop);
    }
}


void drawRain() {
    double x, y, z;
    for (loop = 0; loop < MAX_PARTICLES; loop=loop+2) {
        if (par_sys[loop].alive) {
            x = par_sys[loop].xpos;
            y = par_sys[loop].ypos;
            z = par_sys[loop].zpos + zoom;

            // Draw particles
            //  glColor3f(0.5, 0.5, 1.0);
            glColor3d((double)183/255,(double)211/255,(double)230/255);
            glBegin(GL_LINES);
            glVertex3d(x, y, z);
            glVertex3d(x, y+0.5, z);
            glEnd();

            // Update values
            //Move
            // Adjust slowdown for speed!
            par_sys[loop].ypos += par_sys[loop].vel / (slowdown*1000);
            par_sys[loop].vel += par_sys[loop].gravity;
            // Decay
            par_sys[loop].life -= par_sys[loop].fade;

            if (par_sys[loop].ypos <= -10) {
                par_sys[loop].life = -1.0;
            }
            //Revive
            if (par_sys[loop].life < 0.0) {
                initParticles(loop);
            }
        }
    }
}



// For Hail
void drawHail() {
    double x, y, z;

    for (loop = 0; loop < MAX_PARTICLES; loop=loop+2) {
        if (par_sys[loop].alive) {
            x = par_sys[loop].xpos;
            y = par_sys[loop].ypos;
            z = par_sys[loop].zpos + zoom;

            // Draw particles
            glColor3f(0.8, 0.8, 0.9);
            glBegin(GL_QUADS);
            // Front
            glVertex3d(x-hailsize, y-hailsize, z+hailsize); // lower left
            glVertex3d(x-hailsize, y+hailsize, z+hailsize); // upper left
            glVertex3d(x+hailsize, y+hailsize, z+hailsize); // upper right
            glVertex3d(x+hailsize, y-hailsize, z+hailsize); // lower left
            //Left
            glVertex3d(x-hailsize, y-hailsize, z+hailsize);
            glVertex3d(x-hailsize, y-hailsize, z-hailsize);
            glVertex3d(x-hailsize, y+hailsize, z-hailsize);
            glVertex3d(x-hailsize, y+hailsize, z+hailsize);
            // Back
            glVertex3d(x-hailsize, y-hailsize, z-hailsize);
            glVertex3d(x-hailsize, y+hailsize, z-hailsize);
            glVertex3d(x+hailsize, y+hailsize, z-hailsize);
            glVertex3d(x+hailsize, y-hailsize, z-hailsize);
            //Right
            glVertex3d(x+hailsize, y+hailsize, z+hailsize);
            glVertex3d(x+hailsize, y+hailsize, z-hailsize);
            glVertex3d(x+hailsize, y-hailsize, z-hailsize);
            glVertex3d(x+hailsize, y-hailsize, z+hailsize);
            //Top
            glVertex3d(x-hailsize, y+hailsize, z+hailsize);
            glVertex3d(x-hailsize, y+hailsize, z-hailsize);
            glVertex3d(x+hailsize, y+hailsize, z-hailsize);
            glVertex3d(x+hailsize, y+hailsize, z+hailsize);
            //Bottom
            glVertex3d(x-hailsize, y-hailsize, z+hailsize);
            glVertex3d(x-hailsize, y-hailsize, z-hailsize);
            glVertex3d(x+hailsize, y-hailsize, z-hailsize);
            glVertex3d(x+hailsize, y-hailsize, z+hailsize);
            glEnd();

            // Update values
            //Move
            if (par_sys[loop].ypos <= -10) {
                par_sys[loop].vel = par_sys[loop].vel * -1.0;
            }
            par_sys[loop].ypos += par_sys[loop].vel / (slowdown*1000); // * 1000
            par_sys[loop].vel += par_sys[loop].gravity;

            // Decay
            par_sys[loop].life -= par_sys[loop].fade;

            //Revive
            if (par_sys[loop].life < 0.0) {
                initParticles(loop);
            }
        }
    }
}

// For Snow
void drawSnow() {
    double x, y, z;
    for (loop = 0; loop < MAX_PARTICLES; loop=loop+2) {
        if (par_sys[loop].alive) {
            x = par_sys[loop].xpos;
            y = par_sys[loop].ypos;
            z = par_sys[loop].zpos + zoom;

            // Draw particles
            glColor3f(1.0, 1.0, 1.0);
            glPushMatrix();
            glTranslated(x, y, z);
            glutSolidSphere(0.2, 16, 16);
            glPopMatrix();

            // Update values
            //Move
            par_sys[loop].ypos += par_sys[loop].vel / (slowdown*1000);
            par_sys[loop].vel += par_sys[loop].gravity;
            // Decay
            par_sys[loop].life -= par_sys[loop].fade;

            if (par_sys[loop].ypos <= -10) {
                int zi = (int)(z - zoom + 10);
                int xi = (int)( x + 10);
                ground_colors[zi][xi][0] = 1.0;
                ground_colors[zi][xi][2] = 1.0;
                ground_colors[zi][xi][3] += 1.0;
                if (ground_colors[zi][xi][3] > 1.0) {
                    ground_points[xi][zi][1] += 0.1;
                }
                par_sys[loop].life = -1.0;
            }

            //Revive
            if (par_sys[loop].life < 0.0) {
                initParticles(loop);
            }
        }
    }
}

// Draw Particles
void drawParticles( ) {
    int i, j;
    double x, y, z;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();


    glRotatef(pan, 0.0, 1.0, 0.0);
    glRotatef(tilt, 1.0, 0.0, 0.0);

    // GROUND?!
    glColor3d(r, g, b);
    glBegin(GL_QUADS);
    // along z - y const
    for (i = -10; i+1 < 11; i++) {
        // along x - y const
        for (j = -10; j+1 < 11; j++) {
            glColor3dv(ground_colors[i+10][j+10]);
            glVertex3d(ground_points[j+10][i+10][0],
                       ground_points[j+10][i+10][1],
                       ground_points[j+10][i+10][2] + zoom);
            glColor3dv(ground_colors[i+10][j+1+10]);
            glVertex3d(ground_points[j+1+10][i+10][0],
                       ground_points[j+1+10][i+10][1],
                       ground_points[j+1+10][i+10][2] + zoom);
            glColor3dv(ground_colors[i+1+10][j+1+10]);
            glVertex3d(ground_points[j+1+10][i+1+10][0],
                       ground_points[j+1+10][i+1+10][1],
                       ground_points[j+1+10][i+1+10][2] + zoom);
            glColor3dv(ground_colors[i+1+10][j+10]);
            glVertex3d(ground_points[j+10][i+1+10][0],
                       ground_points[j+10][i+1+10][1],
                       ground_points[j+10][i+1+10][2] + zoom);
        }

    }
    glEnd();
    // Which Particles
    if (fall == RAIN) {
        drawRain();
    }else if (fall == HAIL) {
        drawHail();
    }else if (fall == SNOW) {
        drawSnow();
    }

    glutSwapBuffers();
}