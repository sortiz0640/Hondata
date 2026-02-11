#ifndef SLQCONNECTION_H
#define SLQCONNECTION_H

#include <soci/soci.h>
#include <soci/odbc/soci-odbc.h>
#include <iostream>
#include <string>

class SqlConnection {
public:
    static soci::session openSession() {
        try {

            std::string connectString =
                        "DRIVER={ODBC Driver 18 for SQL Server};"
                        "SERVER=.\\SQLEXPRESS;"
                        "DATABASE=db_hondata;"
                        "Trusted_Connection=yes;"
                        "TrustServerCertificate=yes;";

            return soci::session(soci::odbc, connectString);

        } catch (const soci::soci_error& e) {
            std::cout << "Error de conexion: " << e.what() << std::endl;
            throw;
        }
    }
};



#endif