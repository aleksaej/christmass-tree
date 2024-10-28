
#include <iostream>
#include <windows.h>  
#include <thread>     
#include <chrono>     
#include <fstream>    
using namespace std;


void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void drawTree(int n, ofstream& file) {
    
    for (int i = 1; i <= n; i++) {
        int rows = i + 1;
        for (int j = 0; j < rows; j++) {
            int stars = 2 * j + 1;
            int spaces = n - j - 1;
            for (int k = 0; k < spaces; k++) {
                cout << " ";
                file << " ";  
            }
            for (int k = 0; k < stars; k++) {
                cout << "*";
                file << "*";  
            }
            cout << endl;
            file << endl;  
        }
    }

 
    int trunkHeight = (n / 2) + 1;              
    int trunkWidth = 3;
    int trunkSpaces = n - 1 - trunkWidth / 2;

    for (int i = 0; i < trunkHeight; i++) {
        for (int j = 0; j < trunkSpaces; j++) {
            cout << " ";
            file << " ";  
        }
        for (int j = 0; j < trunkWidth; j++) {
            cout << "*";
            file << "*";  
        }
        cout << endl;
        file << endl;  
    }
}

int main() {
    int n;
    cout << "Введіть кількість рівнів ялинки: ";
    cin >> n;

    
    ofstream file("tree_archive.txt");
    if (!file) {
        cerr << "Не вдалося відкрити файл для запису!" << endl;
        return 1;
    }

    while (true) {
       
        for (int color = 1; color <= 15; color++) {
            setColor(color);       
            drawTree(n, file);     
            this_thread::sleep_for(chrono::milliseconds(500));  
            system("cls");         
        }
    }

    
    file.close();
    return 0;
}




