#ifndef SQLMANUFACTURERREPOSITORY_H
#define SQLMANUFACTURERREPOSITORY_H

#include "../../src/repositories/interfaces/IManufacturerRepository.h"
#include "../../src/repositories/bin/SqlConnection.h"
#include "../../data/mapper.h"
#include <soci/soci.h>
#include <vector>

class SqlManufacturerRepository : public IManufacturerRepository {
private:
    soci::session& sql;
public:

    SqlManufacturerRepository(soci::session& session) : sql(session) {}

    void add(const ManufacturerDTO& dto) override {

        soci::transaction tr(sql);
        sql << "INSERT INTO Manufacturer (name, legalName, globalSlogan, foundationCountry, foundationYear) "
            "VALUES (:name, :legalName, :globalSlogan, :foundationCountry, :foundationYear)",
            soci::use(dto.name), soci::use(dto.legalName), soci::use(dto.globalSlogan), 
            soci::use(dto.foundationCountry), soci::use(dto.foundationYear);
        tr.commit();
    }

    void update(const ManufacturerDTO& model) override {
        //todo: use to update car information. to define if should be implemented
    }

    void removeById(int id) override {
        soci::transaction tr(sql);
        sql << "DELETE FROM Manufacturer WHERE id = :id", soci::use(id);
        tr.commit();
    }

    ManufacturerDTO findById(int id) override {

        ManufacturerDTO model;

        sql << "SELECT id, name, legalName, globalSlogan, foundationCountry, foundationYear FROM Manufacturer WHERE id = :id", 
        soci::into(model.id), soci::into(model.name), soci::into(model.legalName), soci::into(model.globalSlogan), 
        soci::into(model.foundationCountry), soci::into(model.foundationYear),
        soci::use(id);

        return model;

    }

    std::vector<ManufacturerDTO> findAll() override {

        std::vector<ManufacturerDTO> manufacturers;

        soci::rowset<soci::row> rs = (
            sql.prepare << "SELECT id, name, legalName, globalSlogan, foundationCountry, foundationYear FROM Manufacturer"
        );

            for (auto it = rs.begin(); it != rs.end(); ++it) {
                ManufacturerDTO m;

                m.id = it->get<int>(0);
                m.name = it->get<std::string>(1);
                m.legalName = it->get<std::string>(2);
                m.globalSlogan = it->get<std::string>(3);
                m.foundationCountry = it->get<std::string>(4);
                m.foundationYear = it->get<int>(5);

                manufacturers.push_back(m); // pushes a car into the vector cars 
            }
        
        return manufacturers;
    }
};

#endif