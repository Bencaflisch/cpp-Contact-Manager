#include <iostream> 
#include <cstdlib> 
#include <string>
#include <iomanip> 
using namespace std; 

//Global Variables
 string nameArray[99] = {""}; 
 string numberArray[99] = {""}; 
 int arraySize = 0;

//Input Function
void getData() {
    // Fill the arrays with contact information 
    cout<<"Please enter a contact name: "<<endl; 
    cin>>nameArray[arraySize]; 
    cout<<"Please enter a number for "<< nameArray[arraySize]<<" :"<<endl; 
    cin>>numberArray[arraySize]; 
    arraySize++;
}

//Sort Acending
void sortAce() {
    string temp = ""; 
    int index = -1; 
    int pass = -1; 

    for (pass = 0; pass < arraySize; pass++){ 
        for (index = 0; index < arraySize - 1 - pass; index++){ 
            if ( numberArray[index] > numberArray[index + 1] ){ 

                //swap current number array position with next in array 
                temp = numberArray[index]; 
                numberArray[index] = numberArray[index + 1]; 
                numberArray[index + 1] = temp; 

                //swap current name array position with next in array 
                temp = nameArray[index]; 
                nameArray[index] = nameArray[index + 1]; 
                nameArray[index + 1] = temp; 
            } 
        } 
    }
}

//Sort Decending
void sortDec() {
 string temp = ""; 
    int index = -1; 
    int pass = -1; 

    for (pass = 0; pass < arraySize; pass++){ 
        for (index = 0; index < arraySize - 1 - pass; index++){ 
            if ( numberArray[index] < numberArray[index + 1] ){ 

                //swap current number array position with next in array 
                temp = numberArray[index]; 
                numberArray[index] = numberArray[index + 1]; 
                numberArray[index + 1] = temp; 

                //swap current name array position with next in array 
                temp = nameArray[index]; 
                nameArray[index] = nameArray[index + 1]; 
                nameArray[index + 1] = temp; 
            } 
        } 
    }
}


//Print
void print() {
    for (int i=0; i<arraySize; i++){ 
        cout<<setw(2)<< i+1<<". "<<"Name: "<<setw(2)<<nameArray[i]<<" | "<<"Number: "<<setw(2)<<numberArray[i]<<endl; 
    }
}

//Search
void search() {
    string searchTerm = ""; 
    int foundName = 0; 
    cout<<"Please enter a name to find number"<<endl; 
    cin>>searchTerm; 
    for (int i=0; i < arraySize; i++){ 
        if(searchTerm == nameArray[i]){ 
            cout<<"Number: "<<numberArray[i]<<endl; 
            foundName = 1; 
        } 
    }

 //If no name was found in search 
    if(!foundName){ 
        cout<<"The name you entered was not found. Sorry!"<<endl; 
    }
}

//Menu operations
void menuSelect(int choice) {

    switch (choice){
        case 1: getData();
            break;
        case 2: sortAce();
            break;
        case 3: sortDec();
            break;
        case 4: print();
            break;
        case 5: search();
            break;
   
    }
} 

//Menu
void printMenu(){
    
    bool shouldQuit = 0;

    while (!shouldQuit)
    {
        string menuChoice = "";

        cout << "\n====== MENU ======"<<endl;
        cout << "Enter Contact: 1 "<<
            "\nSort Acending: 2 "<<
            "\nSort Decending: 3 "<<
            "\nPrint Contacts: 4 "<<
            "\nSearch Contacts: 5 "<<
            "\nExit The Program: 6 "<<
            "\n=================="<<endl;
        cin>>menuChoice; 

        if(menuChoice == "6"){
            shouldQuit = 1;
        }else if(menuChoice == "1" || 
                menuChoice == "2" || 
                menuChoice == "3" || 
                menuChoice == "4" || 
                menuChoice == "5"){
            menuSelect(stoi(menuChoice));
        }else{
            cout << "\nIncorrect Selection. Try Again!"<<endl;
        }
    }   
}  


int main() 
{
 printMenu();

 return 0;
}
