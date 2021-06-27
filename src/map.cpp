#include <iostream>
#include <fstream>
#include <typeinfo>

int main(){

        std::ifstream file("quotes.txt",std::ios::binary);
        std::fstream map("quotes.map",std::ios::binary|std::ios::out);
        
        std::string line;
        unsigned int position=0;
        file.seekg(0,std::ios::beg);
        map.write(reinterpret_cast<char*>(&position),sizeof(unsigned int));
        std::cout<<file.tellg()<<std::endl;
        while(getline(file,line)){
                position=file.tellg();
                std::cout<<position<<std::endl;
                
                map.write(reinterpret_cast<char*>(&position),sizeof(unsigned int));
        }
        file.close();
        map.close();
        return 0;
}
