#include <iostream>
#include <string>

class Pokemon
{
    protected:
        std::string name;
        int id;
        std::string  properties;
        std::string  roar;
        int basehp;
    public:
        Pokemon(const std::string &name, int id, std::string properties, std::string roar, int basehp=0)
            : name(name), id(id), properties(properties), roar(roar), basehp(basehp)
        {}
        ~Pokemon(){
            std::cout<<"\n"<<name<<" is fainted";
        }
        void roaring(){
            std::cout<<roar<<"\n";
        }

};
class evolved_Pokemon : public Pokemon{
    public:
        evolved_Pokemon(const std::string &name, int id, std::string properties, std::string roar, int basehp=0)
            : Pokemon(name,id,properties,roar,basehp){}
        void roaring(){
            std::cout<<roar<<"\n";
        }
        int thundebolt(){
            return 32;
        }
};

int main()
{
    Pokemon *Pikachu = new Pokemon("Pikachu", 1,"electric","pika pika",30);
    evolved_Pokemon *Raichu = new evolved_Pokemon("Raichu", 2,"electric","raichu raichu",50);
    Pikachu->roaring();
    Raichu->roaring();
    std::cout<<Raichu->thundebolt();
    delete Pikachu;
    delete Raichu;
}
