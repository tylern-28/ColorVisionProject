#include <iostream>
#include <string>

using namespace std;

int main() {

int number1;
int number2;
int number3;
int number4;
int number5;
int number6;
int difference;
int redDifference;
int greenDifference;
int blueDifference;

string colorName;
string colorName2;

bool valid = false;

    while (!valid){
cout << "Enter color one and 3 RGB numbers: ";
cin >> colorName >> number1 >> number2 >> number3;
 if ((number1 > 0 && number1 < 255) &&
        (number2 > 0 && number2 < 255) &&
        (number3 > 0 && number3 < 255)) {
        valid = true;
    } else {
        cout << "Error: enter valid numbers between 0 and 255." << endl;
    }

cout << "Enter color two and 3 RGB numbers: ";
cin >> colorName2 >> number4 >> number5 >> number6;
     if ((number4 > 0 && number4 < 255) &&
        (number5 > 0 && number5 < 255) &&
        (number6 > 0 && number6 < 255)) {
        valid = true;
    } else {
        cout << "Error: enter valid numbers between 0 and 255." << endl;
    }
    }


        int simulateRedFirst = (number1 + number2) / 2;
        int simulatedGreenFirst = simulateRedFirst;
        int simulatedBlueFirst = number3;

        int simulatedRed2 = (number4 + number5) / 2;
        int simulatedGreen2 = simulatedRed2;
        int simulatedBlue2 = number6;




redDifference = number1 - number4;
greenDifference = number2 - number5;
blueDifference = number3 - number6;

    if (redDifference < 0) {
        redDifference = redDifference * -1;
    }
    if (greenDifference < 0) {
        greenDifference = greenDifference * -1;
    }
    if (blueDifference < 0) {
        blueDifference = blueDifference * -1;
    }

    difference = (redDifference + greenDifference + blueDifference) / 3;



if (difference < 30) {
    cout << "The colors are nearly identical high risk of confusion.";
} else if (difference < 80) {
    cout << "The colors are somewhat similar some viewers may struggle.";
} else if (difference < 140) {
    cout << "The colors are moderately distinct.";
} else {
    cout << "The colors are clearly distinguishable.";
}



  return 0;
}
