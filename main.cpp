#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const int MAX_COLORS = 12;
const string DEFAULT_COLOR = "High-Contrast Blue";

void displayHeader();
bool loadColorPalette(const string& filename, vector<string>& colorPalette);
void evaluateColorSafety(string color1, string color2, bool& isSafe);

int main() {
    string filename = "palette_data.txt";
    bool isSafe = false;

    displayHeader();

    vector<string> colorPalette;

    if (loadColorPalette(filename, colorPalette)) {
        cout << endl;
        cout << "[File I/O Success] Loaded colors from " << filename << "." << endl;
    }
    else {
        cout << endl;
        cout << "[File I/O Notice] Could not read file or file is empty. Using default vector palette." << endl;
        colorPalette.clear();
        colorPalette.push_back("High-Contrast Blue");
        colorPalette.push_back("Pure White");
        colorPalette.push_back("Amber Yellow");
        colorPalette.push_back("Jet Black");
        colorPalette.push_back("Emerald Green");
    }

   
    srand(time(0));

    if (colorPalette.size() >= 2) {
        int index1 = rand() % colorPalette.size();
        int index2;
        do {
            index2 = rand() % colorPalette.size();
        } while (index1 == index2); 

        string color1 = colorPalette.at(index1);
        string color2 = colorPalette.at(index2);

        cout << endl;
        cout << "--- Random Evaluation Results ---" << endl;
        cout << "Comparing " << color1 << " and " << color2 << "." << endl;

        evaluateColorSafety(color1, color2, isSafe);

        if (isSafe) {
            cout << "Status: SAFE - High contrast and colorblind friendly." << endl;
        }
        else {
            cout << "Status: WARNING - Potential visibility risk or low contrast." << endl;
        }
    }
    else {
        cout << "Error: Not enough colors in the palette to compare." << endl;
    }

    return 0;
}

void displayHeader() {
    cout << "========================================" << endl;
    cout << "    COLORBLIND-SAFE COLOR ANALYZER      " << endl;
    cout << "========================================" << endl;
}


bool loadColorPalette(const string& filename, vector<string>& colorPalette) {
    ifstream inFile(filename);
    if (!inFile.is_open()){
        return false;
    }
    
    colorPalette.clear();
    string colorName;
    while (getline(inFile, colorName)){
        if (!colorName.empty()){
            colorPalette.push_back(colorName); 
        }
    }
    inFile.close();
    if (colorPalette.empty()){
        return false;
    }
    
    return true;
}


void evaluateColorSafety(string color1, string color2, bool& isSafe) {

    if ((color1 == "High Contrast Blue" && color2 == "Pure White") || 
        (color1 == "Pure White" && color2 == "High Contrast Blue") ||
        (color1 == "Amber Yellow" && color2 == "Jet Black") ||
        (color1 == "Jet Black" && color2 == "Amber Yellow") ||
        (color1 == "Deep Navy" && color2 == "Pure White") ||
        (color1 == "Pure White" && color2 == "Deep Navy") ||
        (color1 == "Bright Orange" && color2 == "Jet Black") ||
        (color1 == "Jet Black" && color2 == "Bright Orange") ||
        (color1 == "Emerald Green" && color2 == "Pure White") ||
        (color1 == "Pure White" && color2 == "Emerald Green")){
        isSafe = true;
    }
    else {
        isSafe = false;
    }
}
