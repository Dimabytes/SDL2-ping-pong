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
    size_t found = content.find(name);

    if (found != std::string::npos){
        record = std::stoi(content.substr(found + name.length() + 1, content.substr(found + name.length()).find('\n') - 1));
    } else {
        std::ofstream out;
        out.open("records.txt", std::ios::app);
        out << "\n" << name << " 0";
        out.close(); // закрываем файл
    }
}

void Profile::updateRecord(int newRecord) {
    record = newRecord;
    std::ifstream ifs("records.txt");
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                         (std::istreambuf_iterator<char>()    ) );
    size_t found = content.find(name);
    if (found != std::string::npos){
        content = content.replace(found + name.length() + 1, content.substr(found + name.length()).find('\n') - 1, std::to_string(record));
        std::ofstream out("records.txt");
        out << content;
        out.close(); // закрываем файл
    }
}