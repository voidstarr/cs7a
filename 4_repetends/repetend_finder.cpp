
//Code to search for a repetend in the decimal form of a rational number .
//precondition : a quotient and a divisor , both positive integers .
// postcondition : an array containing the sequence of decimal digits in
// the quotient , the length of the repetend and a sequence of repetend digits .
/*
Enter the dividend and divisor of the rational number whose repetend we seek :
1 17
Here are the digits of the quotient computed :
005882352941176470588235294117647058823529411764705882
352941176470588235294117647058823529411764705882352941
1764705882352941176470588235294117647058823529
4117647058823529411764705882352941176470588235
The repetend is of length 16
The digits of the repetend are
4117647058823529 */

# include <iostream >
using namespace std ;
int main () {
    int dividend, divisor, quotient, remainder;
    vector <short> decimalDigs;
    cout << "\ nEnter the dividend and divisor of the rational number ";
         << " whose repetend we seek :\n";
    cin >> dividend >> divisor;
    for (int i = 0; i < 200; ++ i ) {
        decimalDigs . push_back ( dividend / divisor );
        remainder = dividend % divisor;
        dividend = 10 * remainder;
    }
    
    cout << "\ nHere are the digits of the quotient computed : ";
    for (int i = 0; i < 200; ++ i )
        cout << decimalDigs [ i ];
    // Write code to detect the repetend and its length here
    return 0;
}
