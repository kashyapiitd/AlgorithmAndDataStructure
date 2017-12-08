#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;
std::unordered_map<string,vector<pair<int,int> > > geneHealthMap;
void createGeneHealthMap(std::vector<string>gene, std::vector<int> health)
{
	for (int i = 0; i < gene.size(); i++)
	{
		//cout<<"Push: "<<gene[i]<<endl;
		geneHealthMap[gene[i]].push_back(make_pair(i,health[i]));
	}
}
long long int getDnaScore(int first, int last, string dna)
{
	//cout<<"DNA is: "<<dna<<endl;
	int index = 0;
	long int score = 0;
	while(index < dna.size())
	{
		string s = dna.substr(index);
		while(s.size() != 0)
		{
			//cout<<"Searching for string: "<<s<<endl;
			unordered_map<string,vector<pair<int,int> > >::iterator it = geneHealthMap.find(s);
			if (it != geneHealthMap.end())
			{
				//cout<<"Found "<<s<<endl;;
				vector<pair<int,int> >data = geneHealthMap.find(s)->second;
				for (int i = 0; i < data.size(); i++)
				{
					int position = data[i].first;
					if (position >= first && position <= last)
					{
						//cout<<"Score for: "<<s<<" is: "<<data[i].second<<endl;
						score = score + (long int)data[i].second;
						//break;
					}

				}
			}
			s = s.substr(0,s.size()-1);
		}
		index++;
		//index = index + s.size();
	}
	return score;
}
int main(){
    int n;
    cin >> n;
    vector<string> genes(n);
    for(int genes_i = 0; genes_i < n; genes_i++){
       cin >> genes[genes_i];
    }
    vector<int> health(n);
    for(int health_i = 0; health_i < n; health_i++){
       cin >> health[health_i];
    }
    createGeneHealthMap(genes,health);
    int s;
    cin >> s;
    vector<long long int> dnaScore(s);
    for(int a0 = 0; a0 < s; a0++){
        int first;
        int last;
        string d;
        cin >> first >> last >> d;
        dnaScore[a0] = getDnaScore(first,last,d);
        
    }
    // Compute the min and max DNA  Score
    long long int min = *(std::min_element(dnaScore.begin(),dnaScore.end()));
    long long int max = *(std::max_element(dnaScore.begin(),dnaScore.end()));
    cout<<min<<" "<<max<<endl;
    return 0;
}
