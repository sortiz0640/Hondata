#ifndef MANUFACTURER_H
#define MANUFACTURER_H
#include <string>
#include <memory>

class Manufacturer {
private:

    int id;
    std::string name;
    std::string legalName;
    std::string globalSlogan;
    std::string foundationCountry;
    int foundationYear = 0;

public:

    Manufacturer(
        int id,
        const std::string& name,
        const std::string& legalName,
        const std::string& slogan,
        const std::string& country,
        int year
    ) : id(id), name(name), legalName(legalName), globalSlogan(slogan), foundationCountry(country), foundationYear(year) {}

    int getId() const { return id; }
    const std::string& getName() const { return name; }
    const std::string& getLegalName() const { return legalName; }
    const std::string& getSlogan() const { return globalSlogan; }
    const std::string& getFoundationCountry() const { return foundationCountry; }
    int getFoundationYear() const { return foundationYear; }

};

#endif