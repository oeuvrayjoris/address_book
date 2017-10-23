class Address {
	
public:
	// Getters
	std::string getAddress() const {
		return std::to_string(num) + "," + street + "," + postal_code + "," + city + "," + country;
	}
	int getNum() const {
		return num;
	}

	// Setters
	void setNum(const int newNum) {
		num = newNum;
	}

	void setStreet(const std::string newStreet) {
		street = newStreet;
	}

	void setPostalCode(const std::string newPostalCode) {
		postal_code = newPostalCode;
	}

	void setCity(const std::string newCity) {
		city = newCity;
	}

	void setCountry(const std::string newCountry) {
		country = newCountry;
	}

	void print() {
		std::cout << std::to_string(num) + " " + street + " - " + postal_code + " " + city + ", " + country << std::endl;
	}

	Address() {
		num = 0;
		street = "";
		city = "";
		country = "";
	}

  	Address(int myNum, std::string myStreet, std::string myPostalCode, std::string myCity, std::string myCountry) {
	    num = myNum;
	    street = myStreet;
	    postal_code = myPostalCode;
	    city = myCity;
	    country = myCountry;
  	}

private:
	// Attr
	unsigned int num;
	std::string street;
	std::string postal_code;
	std::string city;
	std::string country;
};