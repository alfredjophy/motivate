#include <iostream>
#include <fstream>
#include <typeinfo>

int main(int argc , char* argv[]){
        
        if(argc != 3){
                std::cout<<"2 arguments are required";
                return 1;
        }
        std::ifstream file(argv[1],std::ios::binary);
        std::fstream map(argv[2],std::ios::binary|std::ios::out);
        
        std::string line;
        unsigned int position=0;
        file.seekg(0,std::ios::beg);
        map.write(reinterpret_cast<char*>(&position),sizeof(unsigned int));
        while(getline(file,line)){
                position=file.tellg();
                map.write(reinterpret_cast<char*>(&position),sizeof(unsigned int));
        }
        file.close();
        map.close();
        return 0;
}
