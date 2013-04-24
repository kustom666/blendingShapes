#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <math.h>
#include <iostream>

void comp_point(float u, float v)
{
    float x = sin(v)*cos(u);
    float y = sin(v)*sin(u);
    float z = cos(v);
    glVertex3f(x,y,z);
}
int main()
{
    // crée la fenêtre
    sf::Window window(sf::VideoMode(600, 600), "OpenGL", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);

    // chargement des ressources, initialisation des états OpenGL, ...
    const double pi = 4.0 * atan(1.0);
    glTranslatef(0.f,0.f,-1.5);
    glRotatef(-45,1.0,0.0,0.0);
    //gluLookAt(1,1,1,0,0,0,0,0,1);
    // la boucle principale
    bool running = true;
    while (running)
    {
        // gestion des évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                // on stoppe le programme
                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {
                // on ajuste le viewport lorsque la fenêtre est redimensionnée
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        // effacement les tampons de couleur/profondeur
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glColor3f(1.0,1.0,1.0);

        float u, v,c=0.f;

        for(u = 0.f; u < 2*pi; u+= 0.1){
            for (v = 0.f; v < pi; v+= 0.1 ){
                glColor3f(u/5*pi,v/5*pi,u/v);
                glBegin(GL_POINTS);
                    comp_point(u,v);
                    comp_point(u+0.1,v);
                    comp_point(u+0.1,v+0.1);
                    comp_point(u,v+0.1);
                glEnd();
            }
        }
        // termine la trame courante (en interne, échange les deux tampons de rendu)
        window.display();
    }

    // libération des ressources...

    return 0;
}