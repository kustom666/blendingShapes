#include "drawer.hpp"
#include "point.hpp"

/*void comp_superface(float u, float v, float ea, float eb)
{
    glBegin(GL_POLYGON);
        comp_superpoint(u,v,ea,eb);
        comp_superpoint(u+0.3,v,ea,eb);
        comp_superpoint(u,v+0.1,ea,eb);
        comp_superpoint(u+0.1,v+0.1,ea,eb);
    glEnd();
}*/

int main(int argc, char **argv)
{
    // crée la fenêtre
    sf::Window window(sf::VideoMode(600, 600), "Blending shapes", sf::Style::Default, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.setf(std::ios::showpoint);
    int par = atoi(argv[1]);
    int mer = atoi(argv[2]);

    // chargement des ressources, initialisation des états OpenGL, ...
    const double pi = 4.0 * atan(1.0);
    glTranslatef(0.f,0.f,-0.5);
    glScalef(0.3,0.3,0.3);  
    float pasp = pi/par;
    float pasm = pi/mer;
    int s=0;

    std::vector<std::vector<Point> > anim;
    for(float alpha = 0.0; alpha <= 1; alpha += 0.1){
        std::vector<Point> buffma;
        for(float u = -pi; u < pi; u +=pasp){
            for(float v = -(pi/2); v< (pi/2) ; v+=pasm){
                Point buffpoint;
                buffpoint.blend_comp(u,v,alpha,0.1,1.0);
                buffma.push_back(buffpoint);

                buffpoint.blend_comp(u+pasp,v,alpha,0.1,1.0);
                buffma.push_back(buffpoint);
                
                buffpoint.blend_comp(u+pasp,v+pasm,alpha,0.1,1.0);
                buffma.push_back(buffpoint);

                buffpoint.blend_comp(u,v+pasm,alpha,0.1,1.0);
                buffma.push_back(buffpoint);
            }
        }
        anim.push_back(buffma);
    }
    //maillage.push_back(ps);

    std::ofstream off;
    off.open ("model.off");
    off << "OFF\n"<< par*mer +2 <<" "<< (par+1) * mer <<" 0\n";
    std::vector<Point> maillage = anim[0];
    for(int it = 0; it < maillage.size()-1; it+=1){

        Point buffpointa = maillage[it];
        off << std::fixed << buffpointa.getX() << " " << std::fixed <<  buffpointa.getY() << " " << std::fixed << buffpointa.getZ() << std::endl;

    }
    int i = 0;
    while(i< maillage.size())
    {
        off << "4 "<< i << " " << i+1 << " " << i+2 << " " << i+3 << std::endl;
        i+=4;
    }
    off.close();
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
            else if(event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                }
                else if(event.key.code == sf::Keyboard::Subtract && s >= 1)
                {
                    s--;
                }
                else if (event.key.code == sf::Keyboard::Add && s < anim.size()-1)
                {
                    s++;
                }
                else if(event.key.code == sf::Keyboard::F)
                {
                    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
                }
                else if(event.key.code == sf::Keyboard::W)
                {
                    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
                }
                else if(event.key.code == sf::Keyboard::P)
                {
                    glPolygonMode( GL_FRONT_AND_BACK, GL_POINT );
                    //glRotatef(-45,1.0,0.0,0.0);
                }
                else if(event.key.code == sf::Keyboard::Down)
                {
                    glRotatef(-10.0,1.0,0.0,0.0);
                }
                else if(event.key.code == sf::Keyboard::Up)
                {
                    glRotatef(10.0,1.0,0.0,0.0);
                }
                else if(event.key.code == sf::Keyboard::Left)
                {
                    glRotatef(10.0,0.0,1.0,0.0);
                }
                else if(event.key.code == sf::Keyboard::Right)
                {
                    glRotatef(-10.0,0.0,1.0,0.0);
                }
                else if (event.key.code == sf::Keyboard::Num1)
                {
                    anim.clear();
                    par++;
                    pasp = pi/par;
                    
                    for(float alpha = 0.0; alpha <= 1; alpha += 0.1){
                        std::vector<Point> buffma;
                        for(float u = -pi; u < pi; u +=pasp){
                            for(float v = -(pi/2); v< (pi/2) ; v+=pasm){
                                Point buffpoint;
                                buffpoint.blend_comp(u,v,alpha,0.1,1.0);
                                buffma.push_back(buffpoint);

                                buffpoint.blend_comp(u+pasp,v,alpha,0.1,1.0);
                                buffma.push_back(buffpoint);
                                
                                buffpoint.blend_comp(u+pasp,v+pasm,alpha,0.1,1.0);
                                buffma.push_back(buffpoint);

                                buffpoint.blend_comp(u,v+pasm,alpha,0.1,1.0);
                                buffma.push_back(buffpoint);
                            }
                        }
                        anim.push_back(buffma);
                    }   
                }
                else if (event.key.code == sf::Keyboard::Num2)
                {
                    anim.clear();
                    mer++;
                    pasm = pi/mer;
                    
                    for(float alpha = 0.0; alpha <= 1; alpha += 0.1){
                        std::vector<Point> buffma;
                        for(float u = -pi; u < pi; u +=pasp){
                            for(float v = -(pi/2); v< (pi/2) ; v+=pasm){
                                Point buffpoint;
                                buffpoint.blend_comp(u,v,alpha,0.1,1.0);
                                buffma.push_back(buffpoint);

                                buffpoint.blend_comp(u+pasp,v,alpha,0.1,1.0);
                                buffma.push_back(buffpoint);
                                
                                buffpoint.blend_comp(u+pasp,v+pasm,alpha,0.1,1.0);
                                buffma.push_back(buffpoint);

                                buffpoint.blend_comp(u,v+pasm,alpha,0.1,1.0);
                                buffma.push_back(buffpoint);
                            }
                        }
                        anim.push_back(buffma);
                    }   
                }
            }
        }
        

        // effacement les tampons de couleur/profondeur
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f(1.0,1.0,1.0);

        std::vector<Point> maillage = anim[s];
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