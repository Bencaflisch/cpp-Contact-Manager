#include <iostream> 
#include <cstdlib> 
#include <iomanip> 
using namespace std; 

int main() 
{ 
    string nameArray[10] = {""}; 
    string numberArray[10] = {""}; 

    int arraySize = 10; 

    // Fill the arrays with contact information 
    cout<<"Please enter 3 contact names: "<<endl; 
    for (int i=0; i < arraySize; i++){ 
        cout<<"Please enter a contact name: "<<endl; 
        cin>>nameArray[i]; 
        cout<<"Please enter a number for "<< nameArray[i]<<" :"<<endl; 
        cin>>numberArray[i]; 
    } 

   //Sort the array in ascending order by phone number 
    string temp = ""; 
    int index = -1; 
    int pass = -1; 

    for (pass = 0; pass < arraySize; pass++){ 
        for (index = 0; index < arraySize - pass; index++){ 
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
    
    //Print out the array contents 
    for (int i=0; i<arraySize; i++){ 
        cout<<setw(2)<< i+1<<". "<<"Name: "<<setw(2)<<nameArray[i]<<" | "<<"Number: "<<setw(2)<<numberArray[i]<<endl; 
    } 

    // Get the search term from the user 
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
    // Search the arry 
    return 0; 
} 