#include "Quick_sort.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>  
#include <algorithm>

// PRUEBAS PARA CONTAR LA CANTIDAD DE CARACTERES DEL ARCHIVO

// std::vector<std::string> getFile(const std::string &file) {
//     std::vector<std::string> file_;
//     std::string line;
//     std::ifstream inputFile(file);

//     while (std::getline(inputFile, line)) {
//         file_.push_back(line);
//     }
//     inputFile.close();
//     return file_;
// }

// int countCharacters(const std::string& file_) {
//     std::ifstream file(file_, std::ios::binary); 
//     if (!file) {
//         std::cerr << "Error abriendo el archivo\n";
//         return -1;
//     }

//     int count = 0;
//     char ch;
//     while (file.get(ch)) { 
//         count++;
//     }
    
//     return count;
// }


// CODIGO REAL 

// Lee el archivo como bytes y los almacena en un vector
std::vector<unsigned char> getBytes(const std::string &file){
    std::vector<unsigned char> bytes;
    std::ifstream inputFile(file, std::ios::binary);

    if(!inputFile){
        std::cerr << "Error abriendo el archivo";
        return bytes;
    }

    unsigned char byte;
    while(inputFile.read(reinterpret_cast<char*>(&byte), sizeof(byte))){
        bytes.push_back(byte);
    }
    inputFile.close();
    return bytes;
}

// Ordena los bytes basado en su valor hexadecimal
void sortBytes(std::vector<unsigned char>& bytes){
    quick_sort(bytes, 0, bytes.size() - 1);
}

// Pasa los bytes ordenados a un nuevo archivo, regresandolos a sus valores originales
void generateFile(const std::vector<unsigned char>& bytes, const std::string& outputFile){
    std::ofstream output(outputFile, std::ios::binary);

    if (!output) {
        std::cerr << "Error creando el archivo.\n";
        return;
    }

    for (const auto &byte : bytes) {
        output.write(reinterpret_cast<const char*>(&byte), sizeof(byte));
    }
    output.close();
}

int main() {
    std::string file = "data.txt";

    // REVISION DE LA CANTIDAD DE CARACTERES

    // std::vector<std::string> file_ = getFile(file);
    // int size = countCharacters(file);

    std::vector<unsigned char> bytes = getBytes(file);
    sortBytes(bytes);
    generateFile(bytes, "sorted_data.txt");
    std::cout << "Listo\n";
    return 0;
}
