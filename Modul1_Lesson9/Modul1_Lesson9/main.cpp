#include "Vector3.h"
#include "spaceship.h"
#include "shape.h"

#include <iostream>

using namespace std;

int main()
{
    //FighterShip fighter("F1", Vector3(5.0f, 6.0f, -3.0f), Vector3(1.0f, 1.0f, 0.0f), 100, 0, 10); 
    //BomberShip bomber("B1", Vector3(0.0f, 0.0f, 0.0f), Vector3(1.0f, 0.0f, -1.0f), 79, 0, 5); 

    //fighter.printStats(); 
    //bomber.printStats(); 
    //cout << endl; 

    //fighter.fly(); 
    //fighter.fireLaserGun(); 
    //fighter.fireMissile(); 
    //fighter.fireMissile(); 

    //bomber.fly(); 
    //bomber.dropBomb(); 
    //bomber.dropBomb(); 

    Shape* shapes[10]; 
    shapes[0] = new Circle(1.0f); 
    shapes[1] = new Circle(2.0f); 
    shapes[2] = new Circle(3.0f); 
    shapes[3] = new Circle(4.0f); 
    shapes[4] = new Circle(5.0f); 
    shapes[5] = new Rectangle(1.0f, 2.0f); 
    shapes[6] = new Rectangle(2.0f, 4.0f); 
    shapes[7] = new Rectangle(3.0f, 1.0f); 
    shapes[8] = new Rectangle(4.0f, 6.0f); 
    shapes[9] = new Rectangle(5.0f, 2.0f);

    for(int i = 0; i < 10; ++i) 
    { 
        string type = shapes[i]->type(); 
        float area = shapes[i]->area(); 
        float peri = shapes[i]->perimeter(); 
        cout << "Shape[" << i << "]'s "; 
        cout << "Type = " << type << ", "; 
        cout << "Area = " << area << ", "; 
        cout << "Perimeter = " << peri << endl; 
        shapes[i]->draw();
    } 

    // Delete the memory. 
    for(int i = 0; i < 10; ++i) 
    { 
        delete shapes[i]; 
    } 

    cin.get();
}