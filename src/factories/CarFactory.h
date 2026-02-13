#ifndef CARFACTORY_H
#define CARFACTORY_H

#include "../../src/data/CarDTO.h"
#include "../../src/data/ModelDTO.h"
#include "../../src/data/EngineInstanceDTO.h"
#include "../../src/models/Car.h"
#include <stdexcept>
#include <memory>

class CarFactory {
public:

    static CarDTO buildDTO (int idModel, int idEngineInstance, const std::string& color, const std::string& transmission ) {

        if (color.empty()) { throw std::invalid_argument("Color can not be empty."); }
        if (transmission.empty()) { throw std::invalid_argument("Transmission can not be empty."); }
        if (transmission != "Manaul" && transmission != "Automatic") { throw std::invalid_argument("Invalid transmission type"); }
        
        CarDTO dto;
        dto.idModel = idModel;
        dto.idEngineInstance = idEngineInstance;    
        dto.color = color;
        dto.transmission = transmission;

        return dto;

    }

    static Car buildFromDTO (const CarDTO& carDTO, const ModelDTO& model, const EngineInstanceDTO& engine) {


        auto m = std::make_shared<Model>(ModelFactory::buildFromDTO(model));
        auto e = std::make_unique<EngineInstance>(EngineInstanceFactory::buildFromDTO(engine));

        return Car(
            carDTO.id,
            carDTO.color,
            carDTO.transmission,
            m,
            std::move(e)
        );
    }
};


#endif