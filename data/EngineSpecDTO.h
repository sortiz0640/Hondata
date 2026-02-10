#ifndef ENGINSPECDTO_H
#define ENGINESPECDTO_H
#include <string>

struct EngineSpecDTO {

    int id; // PRIMARY KEY FROM DB
    int idManufacturer; // FOREING KEY FROM Manufacturer
    std::string configuration;
    std::string fuel;
    std::string power;
    std::string torque;
    std::string compression;
    bool hasVTEC;

    EngineSpecDTO() : id(0), idManufacturer(0), hasVTEC(false) {}

    EngineSpecDTO (
        int id,
        int m,
        const std::string& c,
        const std::string& f,
        const std::string& p,
        const std::string& t,
        const std::string& cp,
        bool hasVTEC
    ) : id(id), idManufacturer(m), configuration(c), fuel(f), power(p), torque(t), compression(cp), hasVTEC(hasVTEC) {}
};

#endif