#include <iostream>
#include <time.h>
#include <fstream>
#include <ios>
#include <vector>
#include <algorithm>


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
int ConsoleInputArray(int size, int A[])
{
    for (int i = 0; i < size; i++) {
        cout << "Array[ " << i << "] "; 
        cin >> A[i];
    }
    return size;
}

// генератор звич масив
int RandomInputArray(int size, int A[])
{   
    srand(time(NULL));
    cout << "\nArray:\n";
    for (int i = 0; i < size; i++) {
        A[i] = rand() % 100 - 50;
        cout << A[i] << "   ";
    }
    return size;
}
// вектор заповнення
void ConsoleInputVector(int sizeMax, vector<int>& A)
{
    int size = ConsoleInputSizeArray(sizeMax);
    int d;
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; 
        cin >> d; 
        A.push_back(d);
    }
    return;
}
// масив в файл
void WriteArrayTextFile(int size, int* b, const char* fileName)
{   
    ofstream fout(fileName);
    if (fout.fail()) return;
    fout << size << endl;
    for (int i = 0; i < size; i++)
        fout << b[i] << "   ";
    fout.close(); //
}

// масив в бінарний файл
void WriteArrayBinFile(int size, int* b, const char* fileName)
{   
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&size, sizeof(int));
    std::streamsize  cn = static_cast<std::streamsize>(size) * sizeof(double);
    bfout.write((const char*)b, cn);
    bfout.close();
}



//вектор в текстовий файл
void WriteVectorTextFile(int size, vector<int>* b, const char* fileName)
{
    ofstream fout(fileName);
    if (fout.fail()) return;
    fout << size << endl;
    for (int num : *b) {
        fout << num << "  ";
    }
    fout.close(); //
}


// вектор в бінарний файл
void WriteVectorBinFile(int size, vector<int>* b, const char* fileName)
{
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&size, sizeof(int));
    std::streamsize  cn = static_cast<std::streamsize>(size) * sizeof(double);
    bfout.write((const char*)b, cn);
    bfout.close();
}


// завдання перше
int Task1(int size, int A[], int B[]) {
    cout << endl << "Array B:" << endl;
    int j = 0;
    for (int i = 0; i < size; i++)
       {
           if (A[i] < 0) {
                B[j] = A[i];
                cout << B[j] << " ";
                j++;
           }
       }
    return j;
}
//завдання друге
int Task2(int size, int* arr) {
    int max = -1000, T;
    cout << "Input T: "; cin >> T;
    for (int i = 0; i < size; i++)
    {
        if (T == *(arr + i)) {
            break;
        }
        else
        {
            if (max < (*(arr + i)) && (*(arr+i)) < 0) {
                max = *(arr + i);
            }
        }
    }
    return max;
}
//завдання третє
void Task3(std::vector<int>& A, std::vector<int>& B) {
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    B.resize(A.size());
    copy(A.begin(), A.end(), B.begin());
    int count = 0; 
    cout << endl;
    for (int num : B) {
            cout << num << " ";
            count++;
            if (count % 5 == 0) {
                cout << endl;
            }
    }
}
int main()
{
    int A[sizeMax], B[sizeMax];
    int* dynamicA = nullptr;
    vector <int> vectorA;
    vector <int> vectorB;
    int choise, size;
    ShowMainMenu();
    cin >> choise;
    switch (choise)
    {
    case 1://task 1
        MenuInput();
        cin >> choise;
            switch (choise)
            {
            case 1:
                size = ConsoleInputSizeArray(sizeMax);
                ConsoleInputArray(size, A);
                Task1(size, A, B);
                break;
            case 2:
                size = ConsoleInputSizeArray(sizeMax); 
                RandomInputArray(size, A);
                Task1(size, A, B);
                break;
            case 3:
                size = ConsoleInputSizeArray(sizeMax); 
                RandomInputArray(size, A);
                size = Task1(size, A, B);
                WriteArrayTextFile(size, B, "output.txt");
                break;
            case 4:
                size = ConsoleInputSizeArray(sizeMax); 
                RandomInputArray(size, A);
                size = Task1(size, A, B);
                WriteArrayBinFile(size, B, "binoutput.bin");
                break;
            }

        break;

    case 2:// Task 2
        size = ConsoleInputSizeArray(sizeMax);
        dynamicA = new int[size];
        ConsoleInputArray(size, dynamicA);
        cout << endl <<Task2(size, dynamicA);
        WriteArrayTextFile(size, dynamicA, "output.txt");
        WriteArrayBinFile(size, dynamicA, "binoutput.bin");
        delete[]dynamicA;
        break;
    case 3:
        ConsoleInputVector(sizeMax, vectorA);
        Task3(vectorA, vectorB);
        WriteVectorTextFile(vectorB.size(), &vectorB, "vectorText.txt");
        WriteVectorBinFile(vectorB.size(), &vectorB, "vectorBin.bin");
        break;
    }
    
    return 0;
}

