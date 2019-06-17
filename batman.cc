#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();
    int HL = 0, WL = 0;
    // game loop
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();
        if (bombDir == "U")
          {
            H = Y0 - 1;
            Y0 = (Y0 - 1 + HL)/2;
          }
        else if (bombDir == "UR")
          {
            WL = X0 + 1;
            H = Y0 - 1;
            X0 = (X0 + 1 + W)/2;
            Y0 = (Y0 - 1 + HL)/2;
          }
        else if (bombDir == "R")
          {
            WL = X0 + 1;
            X0 = (X0 + 1 + W)/2;
          }

        else if (bombDir == "DR")
          {
            WL = X0 + 1;
            HL = Y0 + 1;
            X0 = (X0 + 1 + W)/2;
            Y0 = (Y0 + 1 + H)/2;
          }
        else if (bombDir == "D")
          {
            HL = Y0 + 1;
            Y0 = (Y0 + 1 + H)/2;
          }

        else if (bombDir == "DL")
          {
            W = X0 - 1;
            HL = Y0 + 1;
            X0 = (X0 - 1 + WL)/2;
            Y0 = (Y0 + 1 + H)/2;
          }
         else if (bombDir == "L")
         {
            W = X0 - 1;
            X0 = (X0 - 1 + WL)/2;
         }
         else if (bombDir == "UL")
           {
             W = X0 - 1;
             H = Y0 - 1;
             X0 = (X0 - 1 + WL)/2;
             Y0 = (Y0 - 1 + HL)/2;
           }
        cout << X0 << ' ' << Y0 << endl;
    }
}
