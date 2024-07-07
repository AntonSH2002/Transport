#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <memory>
#include "classes.h"

using namespace std;

int main(int argc, char* argv[])
{
    #ifdef _WIN32
        setlocale(LC_ALL, "Russian");
    #else
        setlocale(LC_ALL, "ru_RU.UTF-8");
    #endif

    if (argc < 2) {
        cerr << "Используйте: " << argv[0] << " 1 2 ... N" << std::endl;
        return 1;
    }

    unordered_map<string, unique_ptr<Factory>> factoryMap;
    factoryMap["0"] = make_unique<MotorcycleFactory>();
    factoryMap["1"] = make_unique<ScooterFactory>();
    factoryMap["2"] = make_unique<CarFactory>();

    vector<unique_ptr<Transport>> transports;
    for (int i = 1; i < argc; i++)
    {
        string type = argv[i];
        auto it = factoryMap.find(type);
        if (it != factoryMap.end())
        {
            transports.push_back(unique_ptr<Transport>(it->second->createTransport()));
        }
        else
        {
            cerr << "Неизвстный тип транспорта: " << type << endl << endl;
        }
    }

    for (const auto& transport : transports)
    {
        transport->getInfo();
    }

	return 0;
}
