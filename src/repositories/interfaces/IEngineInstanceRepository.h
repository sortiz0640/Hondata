#ifndef IENGINEREPOSITORY_H
#define IENGINEREPOSITORY_H

#include "IRepository.h"
#include "../../src/data/EngineInstanceDTO.h"

class IEngineInstanceRepository : public IRepository<EngineInstanceDTO> {
public:

    virtual ~IEngineInstanceRepository() = default;

    // class specific methods to be added here
};

#endif