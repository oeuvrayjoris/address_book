class Book {

    public:
        // Methods
        void print() { // Print address book if file exists; else, a new file is created.
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
                if(n_contacts > 0)
                    std::cout << content;
                else
                    std::cout << "Empty..." << std::endl;

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

    void action(int choice) { // Link choice with corresponding functions 
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
        std::string first_name, last_name, street, postalCode, city, country, name, title;
        int age, number;
        Person newPerson;

        std::cout << std::endl;
        std::cout << "*** ADD A NEW PERSON ***" << std::endl;
        std::cin.clear();  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "First name : ";
        std::getline(std::cin, first_name);

        std::cout << "Last name : ";
        std::getline(std::cin, last_name);

        std::cout << "Age : ";
        std::cin >> age;
        std::cin.clear();  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Address : " << std::endl;
        std::cout << " - Number : ";
        std::cin >> number;
        std::cin.clear();  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << " - Street : ";
        std::getline(std::cin, street);

        std::cout << " - Postal Code : ";
        std::getline(std::cin, postalCode);

        std::cout << " - City : ";
        std::getline(std::cin, city);

        std::cout << " - Country : ";
        std::getline(std::cin, country);

        newPerson.setFirstName(first_name);
        newPerson.setLastName(last_name);
        newPerson.setAge(age);
        newPerson.setAddress(number, street, postalCode, city, country);

        save(newPerson);
    }


    void edit() {
        std::string first_name, last_name, street, postalCode, city, country;
        int age, number, id, choice;
        Person person;

        std::cout << std::endl;
        std::cout << "*** EDIT A PERSON ***" << std::endl;
        std::cout << "Enter id : ";
        std::cin >> id;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        person = getPersonById(id);

        std::cout << std::endl;
        std::cout << "*** Field to edit ***" << std::endl;
        std::cout << "1 - First name" << std::endl;
        std::cout << "2 - Last name" << std::endl;
        std::cout << "3 - Age" << std::endl;
        std::cout << "4 - Address" << std::endl;
        std::cout << "Choice : ";

        while (!(std::cin >> choice) || choice < 1 || choice > 4) {
            std::cout << "Choice not found. Retry: ";  
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << std::endl;
        std::cin.clear();  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice) {
            case 1:
            std::cout << "First name : ";
            std::getline(std::cin, first_name);
            person.setFirstName(first_name);
            break;

            case 2:
            std::cout << "Last name : ";
            std::getline(std::cin, last_name);
            person.setLastName(last_name);
            break;

            case 3:
            std::cout << "Age : ";
            std::cin >> age;
            person.setAge(age);
            std::cin.clear();  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;

            case 4:
            std::cout << "Address : " << std::endl;
            std::cout << " - Number : ";
            std::cin >> number;
            std::cin.clear();  
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << " - Street : ";
            std::getline(std::cin, street);

            std::cout << " - Postal Code : ";
            std::getline(std::cin, postalCode);

            std::cout << " - City : ";
            std::getline(std::cin, city);

            std::cout << " - Country : ";
            std::getline(std::cin, country);

            person.setAddress(number, street, postalCode, city, country);
            break;
        }

        saveId(person, id);
    }

    void remove() { // Remove line in file
        int id=1, id_user;
        std::string line;
        std::cout << std::endl;
        std::cout << "*** REMOVE A PERSON ***" << std::endl;

        std::ifstream file;
        file.open("address_book.txt");
        std::ofstream temp;
        temp.open("temp.txt");
        std::cout << "Enter id : ";
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

    void exportFile() { // Export datas into new text file
        std::string line, filename;
        std::cout << std::endl;
        std::cout << "*** EXPORT ***" << std::endl;

        std::ifstream file;
        file.open("address_book.txt");

        std::cout << "Enter file's name : ";
        std::cin >> filename;
        std::cin.clear();  
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::ofstream newfile;
        newfile.open(filename + ".txt");

        while(getline(file,line)) {
        newfile << line << std::endl;
        }

        newfile.close();
        file.close();
    }

    void exit() { // Close program after 3 seconds
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

    void save(Person newPerson) { // Append a new person to file
        std::ofstream file;
        file.open("address_book.txt", std::ios_base::app);
        file << newPerson.getPerson() << std::endl;
        file.close();
    }

    void saveId(Person person, int id_user) { // Overwrite person at line id_user by person passed as argument
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

    Person getPersonById(int id_user) {
        Person person;
        int id=1;
        std::string line, person_line, word;
        std::ifstream file;
        std::string person_array[8];

        file.open("address_book.txt");

        while(getline(file,line)) {
            if(id == id_user) {
            person_line = line;
            }
            id++;
        }

        file.close();
        std::istringstream ss(person_line);
        id = 0;

        while(std::getline(ss, word, ',')) {
            person_array[id] = word;
            id++;
        }

        person = Person(person_array[0], person_array[1], std::stoi(person_array[2]), std::stoi(person_array[3]), person_array[4], person_array[5], person_array[6], person_array[7]);

        return person;
    }

    private:
        // Attr
        unsigned int n_contacts; // Number of people in the address book

};