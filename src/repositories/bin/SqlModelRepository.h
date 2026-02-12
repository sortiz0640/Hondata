#ifndef SQLMODELREPOSITORY_H
#define SQLMODELREPOSITORY_H

#include "../../src/repositories/interfaces/IModelRepository.h"
#include "../../src/repositories/bin/SqlConnection.h"
#include "../../data/mapper.h"
#include <soci/soci.h>
#include <vector>

class SqlModelRepository : public IModelRepository {
private:
    soci::session& sql;
public:

    SqlModelRepository(soci::session& session) : sql(session) {}

    void add(const ModelDTO& dto) override {

        soci::transaction tr(sql);
        sql << "INSERT INTO Model (name, bodywork, segment, generation, wheeldrive, releaseYear, idManufacturer) "
            "VALUES (:name, :bodywork, :segment, :generation, :wheeldrive, :releaseYear, :idManufacturer)",
            soci::use(dto.name), soci::use(dto.bodywork), soci::use(dto.segment), soci::use(dto.generation), 
            soci::use(dto.wheeldrive), soci::use(dto.releaseYear), soci::use(dto.idManufacturer);
        tr.commit();
    }

    void update(const ModelDTO& model) override {
        //todo: use to update car information. to define if should be implemented
    }

    void removeById(int id) override {
        soci::transaction tr(sql);
        sql << "DELETE FROM Model WHERE id = :id", soci::use(id);
        tr.commit();
    }

    ModelDTO findById(int id) override {

        ModelDTO model;

        sql << "SELECT id, name, bodywork, segment, generation, wheeldrive, releaseYear, idManufacturer FROM Model WHERE id = :id", 
            soci::into(model.id), soci::into(model.name), soci::into(model.bodywork), soci::into(model.segment), soci::into(model.generation), 
            soci::into(model.wheeldrive), soci::into(model.releaseYear), soci::into(model.idManufacturer), 
            soci::use(id);

        return model;

    }

    std::vector<ModelDTO> findAll() override {

        std::vector<ModelDTO> models;

        soci::rowset<soci::row> rs = (
            sql.prepare << "SELECT id, name, bodywork, segment, generation, wheeldrive, releaseYear, idManufacturer FROM Model"
        );

            for (auto it = rs.begin(); it != rs.end(); ++it) {
                ModelDTO model;

                model.id = it->get<int>(0);
                model.name = it->get<std::string>(1);
                model.bodywork = it->get<std::string>(2);
                model.segment = it->get<std::string>(3);
                model.generation = it->get<std::string>(4);
                model.wheeldrive = it->get<std::string>(5);
                model.releaseYear = it->get<int>(6);
                model.idManufacturer = it->get<int>(7);

                models.push_back(model); // pushes a car into the vector cars 
            }
        
        return models;
    }
};

#endif