#include <fstream>
#include <iostream>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>

using namespace rapidjson;
using namespace std;

int main(int argc,char** argv){

    ifstream ifs("quotes.json");
    IStreamWrapper isw(ifs);
    ofstream data("quotes.dat",ios::binary);

    Document quotes;
    quotes.ParseStream(isw);
    assert(quotes.IsArray());

    for(unsigned long i=0;i<quotes.Size();i++){
        assert(quotes[i].IsObject());
        string q=quotes[i]["quote"].GetString();
        string a=quotes[i]["author"].GetString();

        data.write((char*)&q,sizeof(q));
        data.write((char*)&a, sizeof(a));
        
    }
    return 0;
}
