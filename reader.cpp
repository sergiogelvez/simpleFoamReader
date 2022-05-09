#include <iostream>
#include <vector> 
#include <fstream>

struct double3
{
    double x, y, z;
};

struct float3
{
    float x, y, z;
};


int main() 
{
    using namespace std;
    // código para leer el vector
    int count{525520} ;
    int i;
    vector<float3> MainVec;

    ifstream myfile;
    myfile.open("U", ios::binary | ios::in);
        
    // auto count = fileData.size();
    cout << "El tamaño del archivo es: " << count << endl;

    // hallar largo
    myfile.seekg (0, myfile.end);
    int length = myfile.tellg();
    myfile.seekg (0, myfile.beg);

    std::cout << "Leyendo " << length << " chars (bytes)... " << '\n';

    for (i = 0; i < count ; ++i)
    {
        float3 value ;
        float coord ;
        if (myfile)
        {
            myfile.read(reinterpret_cast<char*>(&coord), sizeof(float));
            value.x = coord;
            myfile.read(reinterpret_cast<char*>(&coord), sizeof(float));
            value.y = coord;
            myfile.read(reinterpret_cast<char*>(&coord), sizeof(float));
            value.z = coord;
            MainVec.push_back(value);
        }
        else
        {
            cout << "Error mugroso en el intento: " << i << '\n';
        }

    }

    // cerrar el archivo
    myfile.close();


    /*for (auto j : MainVec) // access by value, the type of j is float3
        cout << "(" << j.x << "," << j.y << "," << j.z << ")\n" ;
    */cout << '\n';
    // tamaño total en bytes del vector
    float3 value {0, 0 ,0} ;
    size_t tamanno = sizeof(value) * MainVec.size() ;
    cout << "El tamaño del vector completo es: " << MainVec.size() << '\n';
    cout << "El tamaño del vector completo (en bytes) es: " << tamanno << endl;




}