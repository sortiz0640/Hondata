#ifndef IMODELREPOSITORY_H
#define IMODELREPOSITORY_H

#include "IRepository.h"
#include "../../src/data/ModelDTO.h"

class IModelRepository : public IRepository<ModelDTO> {
public:

    virtual ~IModelRepository() = default;

    // class specific methods to be added here
};

#endif