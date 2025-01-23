#include <iostream>  library
using namespace std;

class ScoreCard {
private:
    int totalScore;           // Total score of the player/team
    int totalOutPlayers;      // Total number of players out
    int totalDeliveries;      // Total deliveries faced

public:
    //Constructor to initialize values
    ScoreCard(int score = 0, int outs = 0, int deliveries = 0)
        : totalScore(score), totalOutPlayers(outs), totalDeliveries(deliveries) {}

    //Copy constructor
    ScoreCard(const ScoreCard& other) {
        totalScore = other.totalScore;
        totalOutPlayers = other.totalOutPlayers;
        totalDeliveries = other.totalDeliveries;
    }

    //Function to increment the score
    void incrementScore(int points) {
        if (totalOutPlayers < 11) { //Check if all players are out
            totalScore += points;    //Increment the score
            totalDeliveries++;       //Increment the deliveries count
            cout << "Score incremented by " << points << ". New total score: " << totalScore << endl;
        } else {
            cout << "Cannot increment score. All players are out!" << endl;
        }
    }

    //Function to mark a player as out
    void playerOut() {
        if (totalOutPlayers < 11) { // Check if all players are out
            totalOutPlayers++;        // Increment the out players count
            totalDeliveries++;        // Increment the deliveries count
            cout << "A player got out! Total out players: " << totalOutPlayers << endl;
        } else {
            cout << "All players are already out!" << endl;
        }
    }

    //Function to display the total score and statistics
    void viewTotalScore() const {
        cout << "Total score: " << totalScore << endl;
        cout << "Total out players: " << totalOutPlayers << endl;
        cout << "Total deliveries faced: " << totalDeliveries << endl;
    }
};

int main() {
    //Create the first ScoreCard object with initial values
    ScoreCard object1(100, 0, 0);
    
    //Create the second ScoreCard object as a copy of object1
    ScoreCard object2 = object1;
