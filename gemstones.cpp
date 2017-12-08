#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int gemstones(vector <string> arr){
    // Complete this function
    int result = 0;
    // Take the first String 
    std::string firstRock = arr[0];
    std::sort(firstRock.begin(),firstRock.end());
    std::string::iterator it = std::unique(firstRock.begin(),firstRock.end());
    firstRock.resize(std::distance(firstRock.begin(),it));
    //cout<<"Unique Elements are: "<<firstRock<<endl;
    if (arr.size() == 1)
    {
        result = firstRock.size();
    }
    // Take each unique element from the first rock and search in others
    for (int i = 0; i < firstRock.size(); i++)
    {
        char element = firstRock.at(i);
        int j;
        //cout<<"Searching for element: "<<element<<endl;
        for (j = 1; j < arr.size() ;j++)
        {
            if(arr[j].find(element) == std::string::npos)
            {
                break;
            }
        }
        //cout<<"j is: "<<j<<" and arr.size() - 1 is:  "<<arr.size()<<endl;
        if (j == arr.size() )
        {
            result++;
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = gemstones(arr);
    cout << result << endl;
    return 0;
}
