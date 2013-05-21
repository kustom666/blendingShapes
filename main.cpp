#include "drawer.hpp"
#include "point.hpp"

/*void comp_superface(float u, float v, float ea, float eb)
{
    glBegin(GL_POLYGON);
        comp_superpoint(u,v,ea,eb);
        comp_superpoint(u+0.1,v,ea,eb);
        comp_superpoint(u,v+0.1,ea,eb);
        comp_superpoint(u+0.1,v+0.1,ea,eb);
    glEnd();
}*/

int main()
{
    // crée la fenêtre
    sf::Window window(sf::VideoMode(600, 600), "Blending shapes", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);
    std::vector<Point> maillage;

    // chargement des ressources, initialisation des états OpenGL, ...
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    const double pi = 4.0 * atan(1.0);
    glTranslatef(0.f,0.f,-0.5);
    glRotatef(-45,1.0,0.0,0.0);
    glScalef(0.3,0.3,0.3);

    for(float u = -pi; u < pi; u += 0.1){
        for(float v = -(pi/2); v< (pi/2) ; v+=0.1){
            Point buffpoint;
            buffpoint.comp(u,v);
            maillage.push_back(buffpoint);

            buffpoint.comp(u+0.1,v);
            maillage.push_back(buffpoint);
            
            buffpoint.comp(u+0.1,v+0.1);
            maillage.push_back(buffpoint);

            buffpoint.comp(u,v+0.1);
            maillage.push_back(buffpoint);
        }
    }
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
        glBegin(GL_QUADS);
        for(int it = 0; it < maillage.size()-1; it+=1){
            Point buffpointa = maillage[it];

            glVertex3f(buffpointa.getX(), buffpointa.getY(), buffpointa.getZ());

        }
        glEnd();       
        // termine la trame courante (en interne, échange les deux tampons de rendu)
        window.display();
    }

    // libération des ressources...

    return 0;
}