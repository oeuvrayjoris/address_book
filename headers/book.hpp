class Book {

public:
  // Methods
  void print() {
    std::string line, content;
    int id = 1;
    std::ifstream myfile ("address_book.txt");
    content = "";

    if (myfile.is_open()) {
      while (getline(myfile,line)) {
        content += std::to_string(id) + ". " + line + '\n';
        id++;
      }
      n_contacts = --id;

      std::cout << std::endl;
      std::cout << "*** ADDRESS BOOK (" << n_contacts << ") ***" << std::endl;
      std::cout << content;

      myfile.close();
    }
    else {
      std::cout << std::endl;
      std::cout << "*** ADDRESS BOOK ***" << std::endl;

      std::ofstream outfile ("address_book.txt");
      std::cout << "Empty..." << std::endl;
      outfile.close();
    }
  }

  void action(int choice) {
    switch(choice) {
      case 1:
        add();
      break;

      case 2:
        edit();
      break;

      case 3:
        remove();
      break;

      case 4:
        exportFile();
      break;

      case 5:
        exit();
      break;
    }
  }

  void add() {
    std::string first_name, last_name, street, postalCode, city, country;
    int age, number;
    Person newPerson;

    std::cout << std::endl;
    std::cout << "*** ADD A NEW PERSON ***" << std::endl;
    std::cout << "First name : ";
    std::cin >> first_name;
    std::cout << "Last name : ";
    std::cin >> last_name;
    std::cout << "Age : ";
    std::cin >> age;
    std::cout << "Address : " << std::endl;
    std::cout << " - Number : ";
    std::cin >> number;
    std::cout << " - Street : ";
    std::cin >> street;
    std::cout << " - Postal Code : ";
    std::cin >> postalCode;
    std::cout << " - City : ";
    std::cin >> city;
    std::cout << " - Country : ";
    std::cin >> country;

    newPerson.setFirstName(first_name);
    newPerson.setLastName(last_name);
    newPerson.setAge(age);
    newPerson.setAddress(number, street, postalCode, city, country);

    save(newPerson);
  }

  void edit() {
    std::string first_name, last_name, street, postalCode, city, country;
    int age, number, id;
    Person person;

    std::cout << std::endl;
    std::cout << "*** EDIT A PERSON ***" << std::endl;
    std::cout << "Enter person's id : ";
    std::cin >> id;
    std::cout << "First name : ";
    std::cin >> first_name;
    std::cout << "Last name : ";
    std::cin >> last_name;
    std::cout << "Age : ";
    std::cin >> age;
    std::cout << "Address : " << std::endl;
    std::cout << " - Number : ";
    std::cin >> number;
    std::cout << " - Street : ";
    std::cin >> street;
    std::cout << " - Postal Code : ";
    std::cin >> postalCode;
    std::cout << " - City : ";
    std::cin >> city;
    std::cout << " - Country : ";
    std::cin >> country;

    person.setFirstName(first_name);
    person.setLastName(last_name);
    person.setAge(age);
    person.setAddress(number, street, postalCode, city, country);

    saveId(person, id);
  }

  void remove() {
    int id=1, id_user;
    std::string line;
    std::cout << std::endl;
    std::cout << "*** REMOVE A PERSON ***" << std::endl;

    std::ifstream file;
    file.open("address_book.txt");
    std::ofstream temp;
    temp.open("temp.txt");
    std::cout << "Enter person's id : ";
    std::cin >> id_user;

    while(getline(file,line)) {
      if(id != id_user) {
        temp << line << std::endl;
      }
      id++;
    }

    temp.close();
    file.close();
    std::remove("address_book.txt");
    std::rename("temp.txt","address_book.txt");
  }

  void exportFile() {
    std::string line, filename;
    std::cout << std::endl;
    std::cout << "*** EXPORT ***" << std::endl;

    std::ifstream file;
    file.open("address_book.txt");

    std::cout << "Enter file's name : ";
    std::cin >> filename;

    std::ofstream newfile;
    newfile.open(filename + ".txt");

    while(getline(file,line)) {
      newfile << line << std::endl;
    }

    newfile.close();
    file.close();
  }

  void exit() {
    std::cout << std::endl;
    std::cout << "*** Program will exit in... ***" << std::endl;
    std::cout << "3" << std::endl;
    usleep(1000000);
    std::cout << "2" << std::endl;
    usleep(1000000);
    std::cout << "1" << std::endl;
    usleep(1000000);
    std::exit(EXIT_FAILURE);
  }

  void save(Person newPerson) {
    std::ofstream file;
    file.open("address_book.txt", std::ios_base::app);
    file << newPerson.getPerson() << std::endl;
    file.close();
  }

  void saveId(Person person, int id_user) {
    int id=1;
    std::string line;
    std::ifstream file;
    file.open("address_book.txt");
    std::ofstream temp;
    temp.open("temp.txt");

    while(getline(file,line)) {
      if(id != id_user) {
        temp << line << std::endl;
      }
      else {
        temp << person.getPerson() << std::endl;
      }
      id++;
    }

    temp.close();
    file.close();
    std::remove("address_book.txt");
    std::rename("temp.txt","address_book.txt");
  }

private:
  // Attr
  unsigned int n_contacts; // number of contacts in the book

};