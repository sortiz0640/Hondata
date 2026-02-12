#ifndef SQLCARREPOSITORY_H
#define SQLCARREPOSITORY_H

#include "../../src/repositories/interfaces/ICarRepository.h"
#include "../../src/repositories/bin/SqlConnection.h"
#include "../../data/mapper.h"
#include <soci/soci.h>
#include <vector>

class SqlCarRepository : public ICarRepository {
private:
    soci::session& sql;
public:

    SqlCarRepository(soci::session& session) : sql(session) {}

    void add(const CarDTO& dto) override {

        soci::transaction tr(sql);
        sql << "INSERT INTO Car (color, transmission, idModel, idEngineInstance) "
                "VALUES (:color, :trans, :model, :engine)",
        soci::use(dto.color), soci::use(dto.transmission), soci::use(dto.idModel), soci::use(dto.idEngineInstance);
        tr.commit();
    }

    void update(const CarDTO& car) override {
        //todo: use to update car information. to define if should be implemented
    }

    void removeById(int idCar) override {
        soci::transaction tr(sql);
        sql << "DELETE FROM Car WHERE id = :id", soci::use(idCar);
        tr.commit();
    }

    CarDTO findById(int id) override {

        CarDTO car;

        soci::transaction tr(sql);
        sql << "SELECT id, color, transmission, idModel, idEngineInstance FROM Car WHERE id = :id",
        soci::into(car.id), soci::into(car.color), soci::into(car.transmission), 
        soci::into(car.idModel), soci::into(car.idEngineInstance),
        soci::use(id);
        tr.commit();

        return car;

    }

    std::vector<CarDTO> findAll() override {

        std::vector<CarDTO> cars;

        soci::rowset<soci::row> rs = (
            sql.prepare << "SELECT id, color, transmission, idModel, idEngineInstance FROM Cars"
        );

            for (auto it = rs.begin(); it != rs.end(); ++it) {
                CarDTO car;

                car.id = it->get<int>(0);
                car.color = it->get<std::string>(1);
                car.transmission = it->get<std::string>(2);
                car.idModel = it->get<int>(3);
                car.idEngineInstance = it->get<int>(4);
                
                cars.push_back(car); // pushes a car into the vector cars 
            }
        
        return cars;
    }
};

#endif