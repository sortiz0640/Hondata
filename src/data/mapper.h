#ifndef DTOMAPPER_H
#define DTOMAPPER_H
#include "ManufacturerDTO.h"
#include "ModelDTO.h"
#include "EngineSpecDTO.h"
#include "EngineInstanceDTO.h"
#include "CarDTO.h"
#include "../models/Manufacturer.h"
#include "../models/Model.h"
#include "../models/EngineSpec.h"
#include "../models/EngineInstance.h"
#include "../models/Car.h"
#include <memory>

namespace mapper {

    // [MANUFACTURER MAPPER]

    inline std::shared_ptr<Manufacturer> toModel(const ManufacturerDTO& dto) {
        return std::make_shared<Manufacturer> (
            dto.id,
            dto.name,
            dto.legalName,
            dto.globalSlogan,
            dto.foundationCountry,
            dto.foundationYear
        );
    }

    inline ManufacturerDTO toDTO (int idManufacturer, const Manufacturer& manufacturer) {
        return ManufacturerDTO (
            idManufacturer,
            manufacturer.getName(),
            manufacturer.getLegalName(),
            manufacturer.getSlogan(),
            manufacturer.getFoundationCountry(),
            manufacturer.getFoundationYear()
        );
    }


    // [MODEL MAPPER]
    
    inline std::shared_ptr<Model> toModel(const ModelDTO& dto, std::shared_ptr <Manufacturer> manufacturer) {
        return std::make_shared<Model> (
            dto.id,
            manufacturer, 
            dto.name,
            dto.bodywork,
            dto.segment, 
            dto.generation,
            dto.wheeldrive,
            dto.releaseYear
        );
    }

    inline ModelDTO toDTO(int idModel, int idManufacturer, const Model& model) {
        return ModelDTO (
            idModel,
            idManufacturer,
            model.getName(),
            model.getBodywork(),
            model.getSegment(),
            model.getGeneration(),
            model.getWheeldrive(),
            model.getReleaseYear()
        );
    }

    // [ENGINE SPEC MAPPER]

    inline std::shared_ptr<EngineSpec> toModel (const EngineSpecDTO& dto, std::shared_ptr <Manufacturer> manufacturer ) {
        return std::make_shared<EngineSpec> (
            dto.id,
            manufacturer,
            dto.configuration,
            dto.fuel,
            dto.power,
            dto.torque,
            dto.compression,
            dto.hasVTEC
        );
    }

    inline EngineSpecDTO toDTO (int idEngineSpec, int idManufacturer, const EngineSpec& engineSpec) {
        return EngineSpecDTO (
            idEngineSpec, 
            idManufacturer,
            engineSpec.getConfiguration(),
            engineSpec.getFuel(),
            engineSpec.getPower(),
            engineSpec.getTorque(),
            engineSpec.getCompression(),
            engineSpec.getHasVTEC()
        );
    }


    // [ENGINE INSTANCE MAPPER]

    inline std::unique_ptr<EngineInstance> toModel (const EngineInstanceDTO& dto, std::shared_ptr<EngineSpec> engineInstance ) {
        return std::make_unique<EngineInstance> (
            dto.id,
            engineInstance,
            dto.condition,
            dto.mileage,
            dto.operatingHours,
            dto.isOperative,
            dto.hasOverhaul
        );
    }

    inline EngineInstanceDTO toDTO (int idEngineInstance, int idEngineSpec, const EngineInstance& engine) {
        return EngineInstanceDTO (
            idEngineInstance,
            idEngineSpec,
            engine.getCondition(),
            engine.getMileage(),
            engine.getOperatingHours(),
            engine.getIsOperative(),
            engine.getHasOverhaul()
        );
    }


    // [CAR MAPPER]

    inline std::unique_ptr<Car> toModel (const CarDTO& dto, std::shared_ptr<Model> model, std::unique_ptr<EngineInstance> engineInstance) {
        return std:: make_unique<Car> (
            dto.id,
            dto.color,
            dto.transmission,
            model,
            std::move(engineInstance)
        );
    }

    inline CarDTO toDTO (int idCar, int idModel, int idEngineInstance, const Car& car) {
        return CarDTO(
            idCar,
            idModel,
            idEngineInstance,
            car.getColor(),
            car.getTransmission()
        );
    }


} //namespace mapper

#endif