#include "Profile.h"
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>


Profile::Profile() {
    this->name = "";
    this->points = 0;
    this->record = 5;
}

void Profile::initRecord() {
    std::ifstream ifs("records.txt");
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                         (std::istreambuf_iterator<char>()    ) );
    ifs.close();
    std::string nameToSearch = name;
    nameToSearch.insert(0, "__");
    nameToSearch.append("__");
    size_t found = content.find(nameToSearch);

    if (found != std::string::npos){
        record = std::stoi(content.substr(found + nameToSearch.length() + 1, content.substr(found + nameToSearch.length()).find('\n') - 1));
    } else {
        std::ofstream out;
        out.open("records.txt", std::ios::app);
        out << "\n" << nameToSearch << " 0";
        out.close();
    }
}

void Profile::updateRecord(int newRecord) {
    record = newRecord;
    std::ifstream ifs("records.txt");
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                         (std::istreambuf_iterator<char>()    ) );
    std::string nameToSearch = name;
    nameToSearch.insert(0, "__");
    nameToSearch.append("__");
    size_t found = content.find(nameToSearch);
    if (found != std::string::npos){
        content = content.replace(found + nameToSearch.length() + 1, content.substr(found + nameToSearch.length()).find('\n') - 1, std::to_string(record));
        std::ofstream out("records.txt");
        out << content;
        out.close();
    }
}