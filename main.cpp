#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

const int wsx=400;
const int wsy=400;

int vzoom=10;

sf::RenderWindow mainwin(sf::VideoMode(wsx, wsy), "Newton's Simulacra");
sf::View simview(sf::Vector2f(wsx/2, wsy/2), sf::Vector2f(wsx, wsy));

sf::Event eventhandler;
sf::Color wincolor;

void gridRender(){
    for(int x=0; x<wsx/vzoom; x++){
        sf::Vertex gridline[]=
        {
            sf::Vertex(sf::Vector2f(0, x*vzoom), sf::Color(128,128,128)),
            sf::Vertex(sf::Vector2f(wsy, x*vzoom), sf::Color(128,128,128))
        };

        mainwin.draw(gridline, 2, sf::Lines);
    }

    for(int y=0; y<wsy/vzoom; y++){
        sf::Vertex gridline[]=
        {
            sf::Vertex(sf::Vector2f(y*vzoom, 0), sf::Color(128,128,128)),
            sf::Vertex(sf::Vector2f(y*vzoom, wsx), sf::Color(128,128,128))
        };

        mainwin.draw(gridline, 2, sf::Lines);
    }
}

void menuintf(){
    int selection;


    while(1){
        system("cls");

        std::cout << "Menu:\n" << std::endl;
        std::cout << "1 - Simulation" << std::endl;
        std::cout << "2 - View" << std::endl;
        std::cout << "\n]";

        std::cin >> selection;

        std::cout << "\n";

        switch(selection){
            case 1:
                std::cout << "Simulation:\n" << std::endl;
                std::cout << "1 - Zoom In" << std::endl;
                std::cout << "2 - Zoom Out" << std::endl;
                std::cout << "3 - Move Camera" << std::endl;
                std::cout << "\n]";

                std::cin >> selection;
                std::cout << "\n";

                switch(selection){
                    case 1:
                        vzoom*=10;
                        break;
                    case 2:
                        vzoom*=1/10;
                        break;
                    case 3:
                        int x;
                        int y;

                        std::cout << "X]";
                        std::cin >> x;

                        std::cout << "\nY]";
                        std::cin >> y;

                        simview.setCenter(sf::Vector2f(x, y));

                        std::cout << "\nDone!\n" << std::endl;
                        break;
                    default:
                        std::cout << "That's not a real option." << std::endl;
                        break;
                }

                break;
            case 2:
                std::cout << "View:\n" << std::endl;
                std::cout << "1 - Simulation" << std::endl;
                std::cout << "\n]";

                std::cin >> selection;

                std::cout << "\n";

                switch(selection){
                    case 1:
                        std::cout << "Viewing Simulation:\n" << std::endl;
                        std::cout << "Space:\n" << std::endl;
                        std::cout << "Camera Position: " << simview.getCenter().x << ", " << simview.getCenter().y << std::endl;
                        std::cout << "Camera Zoom: " << vzoom << std::endl;

                        std::cin >> selection;
                        break;
                    default:
                        std::cout << "That's not a real option." << std::endl;
                        break;
                }
            default:
                std::cout << "That's not a real option." << std::endl;
                break;
        }
    }
}

void winRender(){
    mainwin.setView(simview);
    wincolor=sf::Color(255,255,255);

    while(mainwin.isOpen()){
        if(mainwin.pollEvent(eventhandler)){
            if(eventhandler.type==sf::Event::Closed){
                mainwin.close();
                break;
            }
        }

        mainwin.clear(wincolor);

        gridRender();

        mainwin.display();
    }
}

int main(){
    sf::Thread secthread(&menuintf);
    secthread.launch();

    winRender();

    return 0;
}
