
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int theLoveLetterMystery(string s){
    // Complete this function
    int count = 0;
    int i = 0;
    int j = s.size()-1;
    while(i<=j)
    {
    	if (s[i] == s[j])
    	{
    		i++;
    		j--;
    	}
    	else{
    		if (s[i] > s[j])
    		{
    			while(s[i] != s[j])
    			{
    				s[i]--;
    				count++;
    			}
    		}
    		else
    		{
    			while(s[i] != s[j])
    			{
    				s[j]--;
    				count++;
    			}
    		}
    		i++;
    		j--;
    	}
    }
    return count;

}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = theLoveLetterMystery(s);
        cout << result << endl;
    }
    return 0;
}
