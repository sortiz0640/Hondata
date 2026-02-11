#ifndef ENGINSPEC_H
#define ENGINESPEC_H
#include <string>
#include <memory>
#include "Manufacturer.h"

class EngineSpec {
private:

    int id;
    std::shared_ptr <Manufacturer> manufacturer; 
    std::string configuration;
    std::string fuel;
    std::string power;
    std::string torque;
    std::string compression;
    bool hasVTEC;

public:

    EngineSpec (
        int id,
        const std::shared_ptr<Manufacturer>& m, 
        const std::string& config,
        const std::string& fuel,
        const std::string& power,
        const std::string& torque,
        const std::string& compression,
        bool hasVTEC
    ) : id(id), manufacturer(m), configuration(config), fuel(fuel), power(power), torque(torque), compression(compression), hasVTEC(hasVTEC) {}

    int getId() const { return id; }
    std::shared_ptr<Manufacturer> getManufacturer() const { return manufacturer; }
    const std::string& getConfiguration() const { return configuration; }
    const std::string& getFuel() const { return fuel; }
    const std::string& getPower() const { return power; }
    const std::string& getTorque() const { return torque; }
    const std::string& getCompression() const { return compression; }
    bool getHasVTEC() const { return hasVTEC; }


};

#endif