#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    cout << "Insert some numeric values. Insert \"end\" to execute sum and average." << endl;
    int count = 0;
    float sum = 0;
    for(;;)
    {
        cout << "insert: ";
        string stringInserted;
        cin >> stringInserted;
        if(stringInserted.compare("end") == 0)
            break;
        sum += std::stof(stringInserted);
        count++;
    }

    cout << "sum: " << sum << " " << "media: " << sum/count << endl;

    return 0;
}
