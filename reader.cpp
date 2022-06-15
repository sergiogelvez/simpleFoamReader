#include <iostream>
#include <vector> 
#include <fstream>
#include <sstream>


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
    int countV{0};
    int corte{10};
    vector<double3> VelVec, PosVec;
    // Para leer las velocidades por celda
    ifstream myfile;
    myfile.open("U", ios::in);
    std::string line;
    while (std::getline(myfile, line) && countV < corte)
    {
        auto pos1 = line.find_first_not_of(' ');
        auto pos2 = line.find_last_not_of(' ');
        // cout << pos1 << "," << pos2 << '\n';
        if (line[pos1] == '(' && line[pos2] == ')')
        {
            line.erase(pos1,1);
            line.erase(pos2-1,1);
            std::istringstream iss(line);
            double3 value;
            if (!(iss >> value.x >> value.y >> value.z)) 
            {
                cout << "Error mugroso en el intento: " << countV;
                cout << line << '\n';

            } 
            else
            {
                VelVec.push_back(value);
            }
            countV += 1;
            cout << line << '\n';
        } 
    }    
    // Paa leer los centros de las celdas, como aproxomación
    int countC{0};
    myfile.close();
    myfile.open("C", ios::in);
    while (std::getline(myfile, line) && countC < corte)
    {
        auto pos1 = line.find_first_not_of(' ');
        auto pos2 = line.find_last_not_of(' ');
        // cout << pos1 << "," << pos2 << '\n';
        if (line[pos1] == '(' && line[pos2] == ')')
        {
            line.erase(pos1,1);
            line.erase(pos2-1,1);
            std::istringstream iss(line);
            double3 value;
            if (!(iss >> value.x >> value.y >> value.z)) 
            {
                cout << "Error mugroso en el intento: " << countC;
                cout << line << '\n';

            } 
            else
            {
                
                PosVec.push_back(value);
            }
            countC += 1;
            cout << line << '\n';
        } 
    }

    // auto count = fileData.size();
    cout << "El tamaño del archivo es: " << countC << endl;
    myfile.close();
    // hallar largo
    /* myfile.seekg (0, myfile.end);
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

    } */

    // cerrar el archivo
    


    /*for (auto j : MainVec) // access by value, the type of j is float3
        cout << "(" << j.x << "," << j.y << "," << j.z << ")\n" ;
    */cout << '\n';
    // tamaño total en bytes del vector
    float3 value {0, 0 ,0} ;
    size_t tamanno = sizeof(value) * VelVec.size() ;
    cout << "El tamaño del vector completo (vel) es: " << VelVec.size() << '\n';
    cout << "El tamaño del vector completo (pos) es: " << PosVec.size() << '\n';
    cout << "El tamaño del vector completo (en bytes) es: " << tamanno << endl;




}