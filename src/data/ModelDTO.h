#ifndef MODELDTO_H
#define MODELDTO_H
#include <string>

struct ModelDTO {

    int id; // PRIMARY KEY from DB
    int idManufacturer; // FOREING KEY FROM Manufacturer
    std::string name;
    std::string bodywork;
    std::string segment;
    std::string generation;
    std::string wheeldrive;
    int releaseYear = 0;

    ModelDTO() : id(0), idManufacturer(0), releaseYear(0) {}
    
    ModelDTO (
        int id,
        int m,
        const std::string& n,
        const std::string& b,
        const std::string& s,
        const std::string& g,
        const std::string& w,
        int year
    ) : id(id), idManufacturer(m), name(n), bodywork(b), segment(s), generation(g), wheeldrive(w), releaseYear(year) {}

};

#endif