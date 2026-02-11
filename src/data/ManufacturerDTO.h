#ifndef MANUFACTURERDTO_H
#define MANUFACTURERDTO_H
#include <string>

struct ManufacturerDTO {

    int id; // PRIMARY KEY FROM DB
    std::string name;
    std::string legalName;
    std::string globalSlogan;
    std::string foundationCountry;
    int foundationYear = 0;

    ManufacturerDTO() : id(0), foundationYear(0) {}

    ManufacturerDTO(
        int id,
        const std::string& name,
        const std::string& legalName,
        const std::string& slogan,
        const std::string& country,
        int year
    ) : id(id), name(name), legalName(legalName), globalSlogan(slogan), foundationCountry(country), foundationYear(year) {}
};

#endif