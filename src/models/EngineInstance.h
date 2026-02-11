#ifndef ENGINEINSTANCE_H
#define ENGINEINSTANCE_H
#include "EngineSpec.h"
#include <string> 
#include <memory>

class EngineInstance {
private:

    int id;
    std::shared_ptr <EngineSpec> specification;
    std::string condition;
    int mileage = 0;
    int operatingHours = 0;
    bool isOperative;
    bool hasOverhaul;

public:

    EngineInstance (
        int id,
        const std::shared_ptr<EngineSpec>& spec,
        const std::string& condition,
        int mileage,
        int hours,
        bool isOperative,
        bool hasOverhaul

    ) : id(id), specification(spec), condition(condition), mileage(mileage), operatingHours(hours), 
        isOperative(isOperative), hasOverhaul(hasOverhaul) {}

    int getId() const { return id; }
    std::shared_ptr<EngineSpec> getSpecification() const { return specification; }
    const std::string& getCondition() const { return condition; }
    int getMileage() const { return mileage; }
    int getOperatingHours() const { return operatingHours; }
    bool getIsOperative() const { return isOperative; }
    bool getHasOverhaul() const { return hasOverhaul; }

    void setCondition(const std::string& c) { condition = c; }
    void setMileage(int m) { mileage = m; }
    void setOperatingHours(int h) { operatingHours = h; }
    void setIsOperative(bool op) { isOperative = op; }
    void setHasOverhaul(bool oh) { hasOverhaul = oh; }
    
};

#endif