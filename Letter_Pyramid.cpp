#include <iostream>
#include <string>

using namespace std;

int main(){
    /*enter "A"
     * output "A"
     * 
     * entered 
     * "AB"
     * output 
     *  "A"
     * "ABA"
     * */
     
    string inputString {};
    cout << "Enter the string you would like to place into a pyramid" << endl;
    getline(cin, inputString);
    
    int size = inputString.length();
    
    int position {0};
    
    for(char c: inputString){
        // determine the number of spaces to place before the letter
        size_t spaces = size - position;
        while(spaces>0){
            cout<<" ";
            --spaces;
        }
        // display in order up to the current character
        for(size_t j =0; j < position; j++){
            cout<< inputString.at(j);
        }
        
        // display the current center
        cout << c;
        
        // Display the remaining characters in reverse order
        for(int j= position-1; j>=0; --j){
            // line to get rid of the size_t vs int warning if you want
            auto k = static_cast<size_t>(j);
            cout<<inputString.at(k);
        }
        
        cout<< endl;
//        increment the position to add the next letter in the string to the pyramid
        ++position;
    }
    
    return 0;
}
