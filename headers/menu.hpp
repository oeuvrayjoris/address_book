#include "book.hpp"

class Menu {

     public:
          // Methods
          void setChoice() {
               while (!(std::cin >> choice) || choice < 1 || choice > 5) {
                    std::cout << "Choice not found. Retry: ";  
                    std::cin.clear();  
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               }
          }

          unsigned int getChoice() {
               return choice;
          }

          void print() {
               std::cout << std::endl;
               std::cout << "*** MENU ***" << std::endl;
               std::cout << "1 - Add" << std::endl;
               std::cout << "2 - Edit" << std::endl;
               std::cout << "3 - Remove" << std::endl;
               std::cout << "4 - Export" << std::endl;
               std::cout << "5 - Exit" << std::endl;
               std::cout << "Choice : ";
          }

     private:
          // Attr
          unsigned int choice;

};