#include <iostream>
#include <vector>

using namespace std;

int main()
{
    unsigned long long int n, m ,w, p;
    cin >> m;
    cin >> w;
    cin >> p;
    cin >> n;
    unsigned long long int nPasses = 1, nCandies = 0;
    nCandies = m * w;
    if (nCandies >= n)
    	return nPasses;
    else
    {
    	while(nCandies < n)
    	{
    		//cout << nCandies<<endl;
    		unsigned long long int nResourcesWeCanBuy = nCandies / p;
    		nCandies = nCandies % p;
    		while(nResourcesWeCanBuy > 0)
    		{
    			//cout << nCandies << endl;
    			if (m < w)
    			{
    				m++;
    				nResourcesWeCanBuy --;
    			}
    			else if (w <=m)
    			{
    				w++;
    				nResourcesWeCanBuy --;
    			}
    		}
    		//cout << m << w << endl;
    		nCandies += (m * w);
    		nPasses++;
    		cout << "nCandies: "<<nCandies<<" in pass NO: "<<nPasses<<endl;
    	}
    }
    cout << nPasses << endl;
    return 1;

}
