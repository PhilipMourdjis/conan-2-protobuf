#include <iostream>
#include <fstream>
#include <string>
#include "addressbook.pb.h"

// Main function:  Reads the entire address book from a file,
//   adds one person based on user input, then writes it back out to the same
//   file.
int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  if (argc != 2) {
    std::cerr << "Usage:  " << argv[0] << " ADDRESS_BOOK_FILE" << std::endl;
    return -1;
  }

  tutorial::AddressBook address_book;

  {
    // Read the existing address book.
    std::fstream input(argv[1], std::ios::in | std::ios::binary);
    if (!input) {
      std::cout << argv[1] << ": Protobuf test application. Creating a new file." << std::endl;
    } else if (!address_book.ParseFromIstream(&input)) {
      std::cerr << "Failed to parse address book." << std::endl;
      return -1;
    }
  }

  // Add an address.
  tutorial::Person* person = address_book.add_people();
  person->set_id(0);
  person->set_name("Harry James Potter");
  person->set_email("harry.potter@hogwarts.ac.uk");

  tutorial::Person::PhoneNumber* phone_number = person->add_phones();
  phone_number->set_number("+4400100012345");
  phone_number->set_type(tutorial::Person::MOBILE);


  {
    // Write the new address book back to disk.
    std::fstream output(argv[1], std::ios::out | std::ios::trunc | std::ios::binary);
    if (!address_book.SerializeToOstream(&output)) {
      std::cerr << "Failed to write address book." << std::endl;
      return -1;
    }
  }

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  std::cout << "Protobuf test executable completed successfuly. File written: " << argv[1] << std::endl;

  return 0;
}
