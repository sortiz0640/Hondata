#ifndef ENGINEINSTANCEDTO_H
#define ENGINEINSTANCEDTO_H
#include <string> 

struct EngineInstanceDTO {

    int id; // PRIMARY KEY FROM DB
    int idSpecification; // FOREIGN KEY EngineSpec from DB
    std::string condition;
    int mileage;
    int operatingHours;
    bool isOperative;
    bool hasOverhaul;

    EngineInstanceDTO() : id(0), idSpecification(0), mileage(0), operatingHours(0), isOperative(false), hasOverhaul(false) {}

    EngineInstanceDTO (
        int id,
        int spec,
        const std::string& c,
        int m,
        int hours,
        bool i,
        bool h

    ) : id(id), idSpecification(spec), condition(c), mileage(m), operatingHours(hours), 
        isOperative(i), hasOverhaul(h) {}
    
};

#endif