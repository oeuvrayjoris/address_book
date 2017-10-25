class Person {

    public:
        // Getters
        std::string getFirstName() const {
            return first_name;
        }
        std::string getLastName() const {
            return last_name;
        }
        int getAge() const {
            return age;
        }
        std::string getPerson() const {
            return first_name + "," + last_name + "," + std::to_string(age) + "," + address.getAddress() + ",";
        }

        // Setters
        void setFirstName(const std::string newFirstName) {
            first_name = newFirstName;
        }
        void setLastName(const std::string newLastName) {
            last_name = newLastName;
        }
        void setAge(const int newAge) {
            age = newAge;
        }
        void setAddress(const int newNum, const std::string newStreet, const std::string newPostalCode, const std::string newCity, const std::string newCountry) {
            address.setNum(newNum);
            address.setStreet(newStreet);
            address.setPostalCode(newPostalCode);
            address.setCity(newCity);
            address.setCountry(newCountry);
        }

        // Constructors
        Person() {
            first_name = "No first name";
            last_name = "No last name";
            age = 0;
            address = Address();
        }
        Person(std::string myFirstName, std::string myLastName, int myAge, int myNum, std::string myStreet, std::string myPostalCode, std::string myCity, std::string myCountry) {
            first_name = myFirstName;
            last_name = myLastName;
            age = myAge;
            address = Address(myNum, myStreet, myPostalCode, myCity, myCountry);
        }

        // Methods
        void print() {
            std::cout << "First name : " << first_name << std::endl;
            std::cout << "Last name : " << last_name << std::endl;
            std::cout << "Age : " << age << std::endl;
            std::cout << "Address : ";
            address.print();
        }

    private:
      // Attr
      std::string first_name;
      std::string last_name; 
      unsigned int age; 
      Address address;
    };