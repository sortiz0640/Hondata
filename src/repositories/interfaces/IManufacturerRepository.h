#ifndef IMANUFACTURERREPOSITORY_H
#define IMANUFACTURERREPOSITORY_H

#include "IRepository.h"
#include "../../src/data/ManufacturerDTO.h"

class IManufacturerRepository : public IRepository<ManufacturerDTO> {
public:

    virtual ~IManufacturerRepository() = default;

    // class specific methods to be added here
};

#endif