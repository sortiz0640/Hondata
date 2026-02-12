#ifndef SLQCONNECTION_H
#define SLQCONNECTION_H

#include <soci/soci.h>
#include <soci/odbc/soci-odbc.h>
#include <iostream>
#include <string>

class SqlConnection {
private:
    std::unique_ptr<soci::session> session;
    
public:
    SqlConnection() {
        std::string connectString =
                        "DRIVER={ODBC Driver 18 for SQL Server};"
                        "SERVER=.\\SQLEXPRESS;"
                        "DATABASE=db_hondata;"
                        "Trusted_Connection=yes;"
                        "TrustServerCertificate=yes;";
        session = std::make_unique<soci::session>(soci::odbc, connectString);
    }
    
    soci::session& getSession() {
        return *session;
    }
};



#endif

            