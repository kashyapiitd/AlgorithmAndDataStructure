#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minSteps(int n, string B){
    // Complete this function
    string queryString = "010";
    int length = 3;
    int count = 0;
    std::size_t position = B.find(queryString);
    while(position != std::string::npos)
    {
    	count++;
    	//string s = B.substr(position + 3);
    	B = B.substr(position + 3);
    	//cout<<"substr is: "<<B<<endl;
    	//cout<<"count is: "<<count<<endl;
    	position = B.find(queryString);

    }
    return count;
}

int main() {
    int n;
    cin >> n;
    string B;
    cin >> B;
    int result = minSteps(n, B);
    cout << result << endl;
    return 0;
}
