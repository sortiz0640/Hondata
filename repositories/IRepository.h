#ifndef IREPOSITORY_H
#define IREPOSITORY_H


class IRepository {
public:
    virtual void findById();
    virtual void findAll();
    virtual void save();
    virtual void remove();
};

#endif
