#include <iostream>
#include <time.h>
#include <fstream>
#include <ios>
using namespace std;
const int sizeMax = 200;
void ShowMainMenu()
{   
    cout << "Main Menu  \n";
    cout << "1.  Task 1  \n";
    cout << "2.  Task 2  \n";
    cout << "3.  Task 3  \n";
    
}
void MenuInput()
{
    cout << "Menu Input   \n";
    cout << "1.  Console all \n";
    cout << "2.  Console - size, array - random \n";
    cout << "3.  File 1.txt \n";
    cout << "4.  bb    \n";
    cout << "5.  Exit \n";
}



// розмір
int ConsoleInputSizeArray(const int sizeMax) {
    int size = 0;
    cout << "Input size Array ( 0< 1 < " << sizeMax << " ) ";
    cin >> size;
    return size;

}
// звичайний масив
int ConsoleInputArray(int sizeMax, int A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    for (int i = 0; i < size; i++) {
        cout << "Array[ " << i << "] "; 
        cin >> A[i];
    }
    return size;
}
// генератор звич масив
int RandomInputArray(int sizeMax, int A[])
{   
    srand(time(NULL));
    int size = ConsoleInputSizeArray(sizeMax);
    cout << "\nArray:\n";
    for (int i = 0; i < size; i++) {
        A[i] = rand() % 50 - 25;
        cout << A[i] << "   ";
    }
    return size;
}

// масив в файл
void WriteArrayTextFile(int* arr, int* b, const char* fileName)
{   
    arr[sizeMax];
    int j = 0;
    int size = RandomInputArray(sizeMax, arr);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0) {
            b[j] = arr[i];
            cout << b[j] << " ";
            j++;
        }
    }
    ofstream fout(fileName);
    if (fout.fail()) return;
    fout << size << endl;
    for (int i = 0; i < j; i++)
        fout << b[i] << "   ";
    fout.close(); //
}

// масив в бінарний файл
void WriteArrayBinFile(int* arr, int* b, const char* fileName)
{   
    int size = RandomInputArray(sizeMax, arr);
    for (int i = 0, j = 0; i < size; i++)
    {
        if (arr[i] < 0) {
            b[j] = arr[i];
            cout << b[j] << " ";
            j++;
        }
    }
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&size, sizeof(int));
    std::streamsize  cn = static_cast<std::streamsize>(size) * sizeof(double);
    bfout.write((const char*)b, cn);
    bfout.close();
}

void Task1(int A[], int B[]) {
    int choise, size;
    MenuInput();
    cin >> choise;
    switch (choise)
    {
    case 1:
        size = ConsoleInputArray(sizeMax, A);
        cout << endl << endl;
        for (int i = 0, j = 0; i < size; i++)
        {
            if (A[i] < 0) {
                B[j] = A[i];
                cout << B[j] << " ";
                j++;
            }
        }
        break;

    case 2:
        size = RandomInputArray(sizeMax, A);
        cout << endl << endl;
        for (int i = 0, j = 0; i < size; i++)
        {
            if (A[i] < 0) {
                B[j] = A[i];
                cout << B[j] << " ";
                j++;
            }
        }
        break;
    case 3:
        WriteArrayTextFile(A, B, "output.txt");
        break;
    case 4:
        WriteArrayBinFile(A, B, "binoutput.bin");
        break;
    }
}
void Task2(int A[]) {

}
int main()
{

    int A[sizeMax], B[sizeMax];
    Task1(A, B);
    
}

