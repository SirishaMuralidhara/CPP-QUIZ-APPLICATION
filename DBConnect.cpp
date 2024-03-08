
#pragma once


#include <iostream>
#include <stdlib.h>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include "DBConnect.h"


using namespace sql;
using namespace std;
const string server = "tcp://127.0.0.1:3306";
const string username = "root";
const string password = "root";


Connection* DBConnect ::setConnection(){

        try
        {
            driver = get_driver_instance();
            con = driver->connect(server, username, password);
        }
        catch (sql::SQLException e)
        {
            cout << "Could not connect to server. Error message: " << e.what() << endl;
            system("pause");
            exit(1);
        }
        con->setSchema("sqldb");
         return con;

}



