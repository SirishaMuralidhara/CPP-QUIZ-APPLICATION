#pragma once
#include <iostream>
using namespace std;
#include "UserDao.h"
#include "DBConnect.h"
#include "User.h"
#include "Admin.h"
#include "AdminDao.h"
class Application {
public:
	Connection* establishConnection();

};
