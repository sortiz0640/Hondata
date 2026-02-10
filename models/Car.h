#ifndef CAR_H
#define CAR_H
#include "EngineInstance.h"
#include "Model.h"
#include <memory>
#include <string>

class Car {
private:

    std::string color;
    std::string transmission;
    std::shared_ptr <Model> model;
    std::unique_ptr <EngineInstance> engine;

public:

    Car (
        const std::string& c, 
        const std::string& t,
        const std::shared_ptr <Model>& m,
        std::unique_ptr <EngineInstance>&& e // movemos el valor de e al atributo engine, no se puede copiar!!
    ) : color(c), transmission(t), model(m), engine(std::move(e)) {}

    const std::string& getColor() const { return color; }
    const std::string& getTransmission() const { return transmission; }
    std::shared_ptr<Model> getModel() const { return model; }
    EngineInstance* getEngine() const { return engine.get(); } // RAW POINTER
    void setColor(const std::string& c) { color = c; }
    void setTransmission(const std::string& t) { transmission = t; }

};

#endif