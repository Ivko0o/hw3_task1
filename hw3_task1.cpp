#include <iostream>
#include <new>

int** Input(int& n, int& m);
void Print(int** array, int n, int m);
void Transform(int** array, int n, int m);

using namespace std;

int main()
{   
    int n;
    int m;

   int** array = Input(n, m);
   Transform(array, n, m);
   Print(array, n, m);
  
}

//Creates an 2D array and takes the elements of it
int** Input(int& n, int& m) {


    //This will make the size of the array
    cout << "Create a 2 dimensional array by entering the number of rows and columns" << endl << endl;
    cout << "Enter number of rows: ";
        cin >> n;
    cout << "Enter number of columns: ";
        cin >> m;
        cout << endl;

    //This creates the dynamic memory array
    int** array = new int* [n]; 
    for (int i = 0; i < n; i++) {
        array[i] = new int[m]; 
    }

    //This will be used to enter the elements of the array
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> array[i][j];
        }
    }

    return array;
}

void Transform(int** array, int n, int m) {

        int d = 0;

        cout << "Enter a number: ";
        cin >> d;
        
        int d1 = 0;                     // Needed for finding the devisors
        int c = 1;                      // Needed for finding the devisors
        int devisors_Count = 1;         

        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                d1 = (array[a][b] / 2);
                //This will count the devisors of the element in the array
                for(int c = 1; c <= d1; c++) {
                    if (array[a][b] % c == 0) {
                        devisors_Count++;
                    }
                }
                //This will change the element to 0 if the devisors count is equal to the number entered by the user
                if (devisors_Count == d) {
                    array[a][b] = 0;
                }
                devisors_Count = 1;    // This resets the count for the next number in the array
            }
        }


}

void Clear(int** array) {

}

//Prints out the array
void Print(int** array, int n, int m) {
    for (int a = 0; a < n; a++) {
        cout << endl;
        for (int b = 0; b < m; b++) {
            cout << array[a][b] << " ";
        }
    }
}

