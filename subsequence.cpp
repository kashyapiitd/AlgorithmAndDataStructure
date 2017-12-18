#include <iostream>
#include <vector>
#include <string>

using namespace std;

int count(string refr, string query )
{
    vector<int> querySizeSeen(query.size(), 0);
    for (int i = 0 ; i < refr.size(); i++)
    {
        for (int j = 0; j < query.size(); j++)
        {
            if (refr[i] == query[j])
            {
                int queryIndex = j;
                if (queryIndex == 0)
                {
                    querySizeSeen[queryIndex]++;
                }
                else
                {
                    querySizeSeen[queryIndex] += querySizeSeen[queryIndex - 1];
                }
            }
        }

    }
    return querySizeSeen[query.size() -1];

}
int main()
{
    //string a = "geeksforgeeks";
    //string b = "gks";
    string a = "3141216732153";
    string b = "123";
    int result =  count(a,b);
    cout << result << endl;
}
