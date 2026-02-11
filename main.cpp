#include "src/repositories/bin/SqlConnection.h"

int main() {
    try {
        std::cout << "Intentando conectar a SQL Server..." << std::endl;
        soci::session sql = SqlConnection::openSession();

        if (sql.get_backend_name() == "odbc") {
            std::cout << "¡Conexion exitosa!" << std::endl;
            
            // Prueba de fuego: Una consulta simple
            std::string server_version;
            sql << "SELECT @@VERSION", soci::into(server_version);
            
            std::cout << "Info del servidor: " << server_version.substr(0, 30) << "..." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Falló la prueba: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}