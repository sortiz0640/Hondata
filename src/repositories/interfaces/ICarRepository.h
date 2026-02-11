#ifndef ICARREPOSITORY_H
#define ICARREPOSITORY_H

#include "IRepository.h"
#include "../../src/data/CarDTO.h"

class ICarRepository : public IRepository<CarDTO> {
public:

    virtual ~ICarRepository() = default;

    // class specific methods to be added here
};

#endif