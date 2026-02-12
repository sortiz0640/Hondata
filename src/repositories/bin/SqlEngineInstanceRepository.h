#ifndef SQLENGINEINSTANCE_H
#define SQLENGINEINSTANCE_H

#include "../../src/repositories/interfaces/IEngineInstanceRepository.h"
#include "../../src/repositories/bin/SqlConnection.h"
#include "../../data/mapper.h"
#include <soci/soci.h>
#include <vector>


class SqlEngineInstanceRepository : public IEngineInstanceRepository {
private:
    soci::session& sql;
public:

    SqlEngineInstanceRepository(soci::session& session) : sql(session) {}  

    void add(const EngineInstanceDTO& dto) override {

        soci::transaction tr(sql);
        sql << "INSERT INTO EngineInstance (condition, mileage, operatingHours, isOperative, hasOverhaul, idEngineSpecification) ",
                "VALUES (:condition, :mileage, :hours, :operative, :overhaul, :spec)";
        soci::use(dto.condition), soci::use(dto.mileage), soci::use(dto.operatingHours), soci::use(dto.isOperative), soci::use(dto.hasOverhaul), soci::use(dto.idSpecification);
        tr.commit();

    }

    void update(const EngineInstanceDTO& dto) override {
        //todo: use to update engine instance information. to define if should be implemented
    }

    void removeById(int idEngineInstance) override {

        soci::transaction tr(sql);
        sql << "DELETE FROM EngineInstance WHERE id = :id", soci::use(idEngineInstance);
        tr.commit();
    
    }

    EngineInstanceDTO findById(int idEngineInstance) override {

        EngineInstanceDTO instance;
        sql <<"SELECT id, condition, mileage, operatingHours, isOperative, hasOverhaul, idEngineSpecification WHERE id = :id FROM EngineInstance", 
        soci::into(instance.id), soci::into(instance.condition), soci::into(instance.mileage), soci::into(instance.operatingHours), soci::into(instance.isOperative),
        soci::into(instance.hasOverhaul), soci::into(instance.idSpecification),
        soci::use(idEngineInstance);
        return instance;

    }

    std::vector<EngineInstanceDTO> findAll() override {

        std::vector<EngineInstanceDTO> instances;

        soci::rowset<soci::row> rs = (
            sql.prepare << "SELECT id, condition, mileage, operatingHours, isOperative, hasOverhaul, idEngineSpecification FROM EngineInstance"
        );

            for (auto it = rs.begin(); it != rs.end(); ++it) {
                EngineInstanceDTO engine;

                engine.id = it->get<int>(0);
                engine.condition = it->get<std::string>(1);
                engine.mileage = it->get<int>(2);
                engine.operatingHours = it->get<int>(3);
                engine.isOperative = it->get<int>(4);
                engine.hasOverhaul = it->get<int>(5);
                engine.hasOverhaul = it->get<int>(6);
                
                instances.push_back(engine); // pushes a EngineInstance into the vector instances 
            }
        
        return instances;

    }  
};

#endif