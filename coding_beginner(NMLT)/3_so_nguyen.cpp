#include <iostream>
#include <string>

class Pokemon 
{
    public:
        std::string name;
        int id;
        std::string  properties;
        std::string  roar;
        Pokemon(std::string name, int id, std::string properties, std::string roar)
            : name(name), id(id), properties(properties), roar(roar)
        void roaring (){
            std::cout<<roar;
        }
};

int main()
{
    Pokemon *Pikachu = new Pokemon("Pikachu", 1,"electric");

}