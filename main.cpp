// 	g++ -I .\boostSerialize main.cpp -o main .\boostSerialize\lib\libboost_serialization-mgw63-mt-1_62.a

#include "VectorSerialize.h"
#include <boost/Serialization/vector.hpp>
#include <fstream>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <iostream>

using namespace std;

class Employee
{
private:
   friend class boost::serialization::access;
   int id;
   string name;
   float salary;

   friend ostream &operator<<(ostream &outDev, const Employee &e)
   {
      outDev << "id: " << e.id << endl;
      outDev << "name: " << e.name << endl;
      outDev << "salary: " << e.salary;
      return outDev;
   }

   template <class Archive>
   void serialize(Archive &a, const unsigned version)
   {
      a &id &name &salary;
   }

public:
   Employee() {}
   Employee(int i, string n, float s) : id(i), name(n), salary(s)
   {
   }
};

namespace demo
{
   void demo()
   {
      const string filename = "data.bin";
      Employee e1(11, "Harry", 4500.00f);
      Employee e2(22, "Ravi", 8800.00f);
      Employee e3(33, "Tim", 6800.00f);
      Employee e4(44, "Rajiv", 3400.00f);

      // Serialize and persist the object
      {
         std::ofstream outfile(filename, ios::binary);
         boost::archive::binary_oarchive archive(outfile);
         archive << e1 << e2 << e3 << e4;
      }

      // Deserialize and restore the object
      Employee restored_e1;
      Employee restored_e2;
      Employee restored_e3;
      Employee restored_e4;

      {
         std::ifstream infile(filename);
         boost::archive::binary_iarchive archive(infile, ios::binary);
         archive >> restored_e1 >> restored_e2 >> restored_e3 >> restored_e4;
      }

      cout << restored_e1 << endl;
      cout << restored_e2 << endl;
      cout << restored_e3 << endl;
      cout << restored_e4 << endl;
   }

   // Built in VectorSerialize
   void demoWithVector()
   {
      const string filename = "data.bin";
      Employee e1(11, "Harry", 4500.00f);
      Employee e2(22, "Ravi", 8800.00f);
      Employee e3(33, "Tim", 6800.00f);
      Employee e4(44, "Rajiv", 3400.00f);
      vector<Employee> employees({e1, e2, e3, e4});

      VectorSerialize<Employee> vs(employees);
      cout << "--------- Deserialized data ------------" << endl;

      string data = vs.Serialize();

      VectorSerialize<Employee> vs2;
      vs2.DeSerialize(data);

      vector<Employee> restoredEmployees = vs2.rawData();
      for (auto &e : restoredEmployees)
         cout << e << endl
              << endl;

      cout << "------------ Writing to file ------------" << endl;
      vs.writeToFile("dataVector.bin");

      vs2.readFromFile("dataVector.bin");
      restoredEmployees = vs2.rawData();
      for (auto &e : restoredEmployees)
         cout << e << endl
              << endl;
   }
}

int main()
{
   demo::demoWithVector();
   return 0;
}