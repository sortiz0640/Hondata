#ifndef SQLENGINESPEC_H
#define SQLENGINESPEC_H

#include "../../src/repositories/interfaces/IEngineSpecRepository.h"
#include "../../src/repositories/bin/SqlConnection.h"
#include "../../data/mapper.h"
#include <soci/soci.h>
#include <vector>


class SqlEngineSpecRepository : public IEngineSpecRepository {
private:
    soci::session& sql;
public:

    SqlEngineSpecRepository(soci::session& session) : sql(session) {}  

    void add(const EngineSpecDTO& dto) override {

        soci::transaction tr(sql);
        sql << "INSERT INTO EngineSpecification (configuration, fuel, power, torque, compression, hasVTEC, idManufacturer) "
            "VALUES (:config, :fuel, :power, :torque, :compression, :hasVTEC, :idManufacturer)";
        soci::use(dto.configuration), soci::use(dto.fuel), soci::use(dto.power), soci::use(dto.torque), soci::use(dto.compression), soci::use(dto.hasVTEC), soci::use(dto.idManufacturer);
        tr.commit();

    }

    void update(const EngineSpecDTO& dto) override {
        //todo: use to update engine spec information. to define if should be implemented
    }

    void removeById(int idEngineSpec) override {

        soci::transaction tr(sql);
        sql << "DELETE FROM EngineSpecification WHERE id = :id", soci::use(idEngineSpec);
        tr.commit();
    
    }

    EngineSpecDTO findById(int idEngineSpec) override {

        EngineSpecDTO spec;
        sql <<"SELECT id, configuration, fuel, power, torque, compression, hasVTEC, idManufacturer FROM EngineSpecification WHERE id = :id", soci::use(idEngineSpec);
        soci::into(spec.id), soci::into(spec.configuration), soci::into(spec.fuel), soci::into(spec.power), soci::into(spec.torque),
        soci::into(spec.compression), soci::into(spec.hasVTEC), soci::into(spec.idManufacturer);
        return spec;

    }

    std::vector<EngineSpecDTO> findAll() override {

        std::vector<EngineSpecDTO> specs;

        soci::rowset<soci::row> rs = (
            sql.prepare << "SELECT id, configuration, fuel, power, torque, compression, hasVTEC, idManufacturer FROM EngineSpecification"
        );

            for (auto it = rs.begin(); it != rs.end(); ++it) {
                EngineSpecDTO spec;

                spec.id = it->get<int>(0);
                spec.configuration = it->get<std::string>(1);
                spec.fuel = it->get<std::string>(2);
                spec.power = it->get<std::string>(3);
                spec.torque = it->get<std::string>(4);
                spec.compression = it->get<std::string>(5);
                spec.hasVTEC = it->get<bool>(6);
                spec.idManufacturer = it->get<int>(7);

                specs.push_back(spec); // pushes a EngineSpec into the vector specs 
            }
        
        return specs;

    }  
};

#endif