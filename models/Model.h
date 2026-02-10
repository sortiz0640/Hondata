#ifndef MODEL_H
#define MODEL_H

#include <memory>
#include "Manufacturer.h"

class Model {
private:

    std::shared_ptr <Manufacturer> manufacturer;
    std::string name;
    std::string bodywork;
    std::string segment;
    std::string generation;
    std::string wheeldrive;
    int releaseYear = 0;
    
public:

    Model (
        const std::shared_ptr <Manufacturer>& m,
        const std::string& name,
        const std::string& bodywork,
        const std::string& segment,
        const std::string& generation,
        const std::string& wheeldrive,
        int year
    ) : manufacturer(m), name(name), bodywork(bodywork), segment(segment), generation(generation), wheeldrive(wheeldrive), releaseYear(year) {}

    std::shared_ptr<Manufacturer> getManufacturer() const { return manufacturer; }
    const std::string& getName() const { return name; }
    const std::string& getBodywork() const { return bodywork; }
    const std::string& getSegment() const { return segment; }
    const std::string& getGeneration() const { return generation; }
    const std::string& getWheeldrive() const { return wheeldrive; }
    int getReleaseYear() const { return releaseYear; }
};

#endif