#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int alternatingCharacters(string s){
    // Complete this function
    int index = 0;
    int nElementsErased = 0;
    int originalSize = s.size();
    while(index < s.size())
    {	
    	//cout<<"index: "<<index<<endl;
    	while(s[index] == s[index+1] )
    	{
    		s.erase(index+1,1);
    		//cout<<"String after removing: "<<s<<endl;
    		if (index == s.size() - 1)
    			break;
    	}
    	index++;
    }
    //cout<<s<<endl;
    nElementsErased = originalSize - s.size();
    return nElementsErased;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = alternatingCharacters(s);
        cout << result << endl;
    }
    return 0;
}