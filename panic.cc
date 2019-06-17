#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int nbFloors; // number of floors
    int width; // width of the area
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
    int elePos[nbFloors] = {0};
    for (int i = 0; i < nbElevators; i++) {
        int elevatorFloor; // floor on which this elevator is found
        int elevatorPos; // position of the elevator on its floor
        cin >> elevatorFloor >> elevatorPos; cin.ignore();
        elePos[elevatorFloor] = elevatorPos;
    }

    // game loop
    static vector<string> decision = {"WAIT", "BLOCK"};
    while (1) {
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> cloneFloor >> clonePos >> direction; cin.ignore();
        if (exitFloor == 0) {
          if (clonePos == width - 1)
              cout << decision[1] << endl; // action: WAIT or BLOCK
          else
              cout << decision[0] << endl;
        } else if (cloneFloor != exitFloor) {
             if ((clonePos < elePos[cloneFloor] && direction == "LEFT") |
                (clonePos > elePos[cloneFloor] && direction == "RIGHT"))
                cout << decision[1] << endl;
             else
                cout << decision[0] << endl;
          } else {
             if ((clonePos < exitPos && direction == "LEFT") |
                (clonePos > exitPos && direction == "RIGHT"))
                cout << decision[1] << endl;
             else
                cout << decision[0] << endl;
        }
    }
}
