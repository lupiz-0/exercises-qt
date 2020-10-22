#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


int main()
{
    cout << "Insert some numeric values. Push enter without enter the value to  calculate median." << endl;
    vector<float> values;
    for(;;)
    {
        cout << "insert: ";
        string stringInserted;
        getline(std::cin, stringInserted);
        if(stringInserted.size() == 0)
            break;
        values.push_back(std::stof(stringInserted));
    }

    std::sort (values.begin(), values.end());

    float median = 0;
    if(values.size() % 2 == 0) {
        int index0 = values.size()/2;
        int index1 = values.size()/2 - 1;
        median = (values[index0] + values[index1])/2;
    }
    else {
        int index = (values.size() - 1)/2;
        median = values[index];
    }

    cout << "the median of the values: ";
    for(const auto& v: values)
        cout << v << " ";
    cout << "   is: " << median << endl;

    return 0;
}
