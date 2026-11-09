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

int main()
{
    string filename = "palette_data.txt";
    int choice1 = 0;
    int choice2 = 0;
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
        colorPalette.push_back("High Contrast Blue");
        colorPalette.push_back("Pure White");
        colorPalette.push_back("Amber Yellow");
        colorPalette.push_back("Jet Black");
        colorPalette.push_back("Emerald Green");
    }


    cout << endl;
    cout << "Available Color Palette:" << endl;
    for (size_t i = 0; i < colorPalette.size(); ++i){
        cout << i + 1 << ". " << colorPalette.at(i);
        
        if (i < colorPalette.size() - 1){
            cout << ", ";
        }
        else {
            cout << ".";
        }
    }
    cout << endl;

    cout << endl;
    cout << "Select two colors to check for colorblind safety (enter numbers 1-" << colorPalette.size() << "):" << endl;
    cout << "Color 1 choice: ";
    cin >> choice1;
    cout << "Color 2 choice: ";
    cin >> choice2;

    if (choice1 >= 1 && choice1 <= (int)colorPalette.size() && 
        choice2 >= 1 && choice2 <= (int)colorPalette.size()) {
        string selectColor1 = colorPalette.at(choice1 - 1);
        string selectColor2 = colorPalette.at(choice2 - 1);
        
        evaluateColorSafety(selectColor1, selectColor2, isSafe);

        cout << endl;
        cout << "--- Evaluation Results ---" << endl;
        cout << "Comparing " << selectColor1 << " and " << selectColor2 << "." << endl;
        
        if (isSafe){
            cout << "Status: SAFE combination for common color vision deficiencies." << endl;
        }
        else {
            cout << "Status: WARNING - Potential visibility risk or low contrast." << endl;
        }
    }
    else {
        cout << "Error: Invalid color selection numbers entered." << endl;
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
