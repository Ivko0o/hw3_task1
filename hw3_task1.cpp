#include <iostream>
#include <new>

int** Input(int& n, int& m);
void Print(int** array, int n, int m);
void Transform(int**& array, int n, int m);
void Clear(int**& array, int& n, int& m);

using namespace std;

int main()
{   
    int n;
    int m;

   int** array = Input(n, m);
   Print(array, n, m);
   Transform(array, n, m);
   Print(array, n, m);
   Clear(array, n, m);
   Print(array, n, m);
  
}

//Creates an 2D array and inputs the elements in it
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
    for (int a = 0; a < n; a++) {
        array[a] = new int[m]; 
    }

    //This will be used to enter the elements of the array
    cout << "Enter the elements of the array:" << endl;
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            cin >> array[a][b];
        }
    }

    return array;
}

void Transform(int**& array, int n, int m) {

        int d = 0;

        cout << "Enter a number: ";
        cin >> d;
        
        int d1 = 0;                     // Needed for finding the devisors
        int c = 1;                      // Needed for finding the devisors
        int devisors_Count = 1;         // This is set to 1 because it takes the number itself to be a devisor as well 

        for (int a = 0; a < n; a++) {
            for (int b = 0; b < m; b++) {
                d1 = abs(array[a][b] / 2);
                //This will count the devisors of the element in the array
                for(int c = 1; c <= d1; c++) {
                    if (abs(array[a][b] % c) == 0) {
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
//Removes the zeros from the array
void Clear(int**& array, int& n, int& m) {

    //This checks if the row is only with zeros and deletes it if it is
    for (int i = 0; i < n;) {
        bool is_Zero_Row = true;

        for (int j = 0; j < m; j++) {
            if (array[i][j] != 0) {
                is_Zero_Row = false;
                break;
            }
        }

        //If the row is only with 0 it will be deleted
        if (is_Zero_Row) {
            delete[] array[i];

            for (int k = i; k < n - 1; k++) {
                array[k] = array[k + 1];
            }
        
            --n;
        }
        else {
            ++i;
        }
    }

    //This checks if the colums is only with zeros and deletes it if it is
    for (int j = 0; j < m; ) {
        bool is_Zero_Column = true;


        for (int i = 0; i < n; i++) {
            if (array[i][j] != 0) {
                is_Zero_Column = false;
                break;
            }
        }

        if (is_Zero_Column) {
            for (int i = 0; i < n; i++) {
                for (int k = j; k < m - 1; k++) {
                    array[i][k] = array[i][k + 1];
                }
            }
            --m;
        }
        else {
            ++j;
        }
    }
    }
 

//Prints out the array
void Print(int** array, int n, int m) {
    for (int a = 0; a < n; a++) {
        cout << endl;
        for (int b = 0; b < m; b++) {
            cout << array[a][b] << " ";
        }
    }
    cout << endl << endl;
}

