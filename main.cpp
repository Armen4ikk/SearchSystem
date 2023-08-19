#include "process_queries.h"
#include "search_server.h"
#include "test_example_functions.h"
#include "test_framework.h"

#include <execution>
#include <iostream>
#include <string>



int main() {
    system("chcp 65001");   //команда для русского языка в консоли
    SearchServer search_server("and with"s);
    int id = 0;
    for(const std::string &text:
    {
        "white cat and yellow hat",
        "curly cat curly tail"
        "nasty dog with big eyes",
        "nasty pigeon john",
    })
    {
        search_server.AddDocument(++id, text, DocumentStatus::ACTUAL, {1, 2});
    }
    std::cout << "ACTUAL by default:" << std::endl;
    for(const Document &document: search_server.FindTopDocuments("curly nasty cat"))
    {
        PrintDocument(document);
    }
    std::cout << "BANNED:" << std::endl;
    // последовательная версия
    for(const Document &document: search_server.FindTopDocuments(std::execution::seq, "curly nasty cat", DocumentStatus::BANNED))
    {
        PrintDocument(document);
    }
    std::cout << "Even ids:" << std::endl;
    // параллельная версия
}