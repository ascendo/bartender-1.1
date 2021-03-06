#include "../minicsv.h"
#include "../csvreader.h"
#include <iostream>
#include <cassert>
#include <memory>
#include <string>
#include <vector>

using std::string;
using std::endl;
using std::cout;
using std::unique_ptr;
using std::vector;
using barcodeSpace::CSVReader;

int main() {
    
    string filename = "csvreader_test.csv";

    CSVReader<string> reader(filename,true);
    std::vector<std::string> header = reader.Header();
    for(const auto& h : header) {
	cout << h << ",";
    }
    cout << endl;
    header.clear();
    
    while (reader.nextRow(&header)) {
	for (const auto& h : header) {
		cout << h << ',';
	}
	cout << endl;
    }
    cout << reader.TotalRecord() << endl; 
    return 0;
}
