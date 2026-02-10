#ifndef CARDTO_H
#define CARDTO_H

#include <string>
#include <memory>

struct CarDTO {

    int id; // PRIMARY KEY FROM DB
    int idModel; // FOREIGN KEY Model
    int idEngineInstance; // FOREIGN KEY EngineInstance
    std::string color;
    std::string transmission;

    CarDTO() : id(0), idModel(0), idEngineInstance(0) {}

    CarDTO(
        int id,
        int m,
        int e,
        const std::string& c,
        const std::string& t
    ) : id(id), idModel(m), idEngineInstance(e), color(c), transmission(t) {}

};


#endif