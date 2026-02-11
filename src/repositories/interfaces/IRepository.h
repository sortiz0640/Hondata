#ifndef IREPOSITORY_H
#define IREPOSITORY_H

#include<memory>
#include<vector>

template <typename T>
class IRepository {
public:

    virtual ~IRepository() = default;

    virtual void add(const T& entity) = 0;
    virtual void update(const T& entity) = 0;
    virtual void removeById(const int id) = 0;
    virtual T findById(int id) = 0;
    virtual std::vector<T> findAll() = 0;

};

#endif
