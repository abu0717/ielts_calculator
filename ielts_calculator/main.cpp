#include <iostream>
#include <cmath>

using namespace std;

void input_scores(float &listening, float &reading, float &writing, float &speaking) {
    bool validInput = false;
    
    while (!validInput) {
        cout << "Please enter your Listening score (0-9): ";
        cin >> listening;
        
        cout << "Please enter your Reading score (0-9): ";
        cin >> reading;
        
        cout << "Please enter your Writing score (0-9): ";
        cin >> writing;
        
        cout << "Please enter your Speaking score (0-9): ";
        cin >> speaking;

        if (listening >= 0 and listening <= 9 and
            reading >= 0 and reading <= 9 &&
            writing >= 0 and writing <= 9 &&
            speaking >= 0 and speaking <= 9) {
            validInput = true;
        } else {
            cout << "Invalid input. Each score must be between 0 and 9. Please try again." << endl;
        }
    }
}

float calculate_average(float listening, float reading, float writing, float speaking) {
    return (listening + reading + writing + speaking) / 4.0;
}

float round_to_half(float score) {
    return round(score * 2) / 2;
}

int main() {
    float listening, reading, writing, speaking;
    char userChoice;
    bool continueProgram = true;

    while (continueProgram) {
        input_scores(listening, reading, writing, speaking);
        
        float averageScore = calculate_average(listening, reading, writing, speaking);
        float finalBandScore = round_to_half(averageScore);

        cout << "Your average IELTS Band Score is: " << finalBandScore << endl;

        cout << "Would you like to calculate another score? (y/n): ";
        cin >> userChoice;
        
        if (userChoice != 'y' && userChoice != 'Y') {
            continueProgram = false;
        }
    }

    return 0;
}
