#ifndef IENGINESPECREPOSITORY_H
#define IENGINESPECREPOSITORY_H

#include "IRepository.h"
#include "../../src/data/EngineSpecDTO.h"

class IEngineSpecRepository : public IRepository<EngineSpecDTO> {
public:

    virtual ~IEngineSpecRepository() = default;

    // class specific methods to be added here
};

#endif