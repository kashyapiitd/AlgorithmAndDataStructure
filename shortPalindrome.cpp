/*
Use this Seq to test : Answer: 877221835
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbb
bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbsactmlkomoyauuqgxomkcrhcyspeezmbyhdejfhyyrljuaslagvbpnxwkcfffrxziduubhmiohjvammfqigjvxtmopwonkgdyrpxostlpjyxy
umwwteraioobereucxcnpggndgjhkjzsynlugkojzkcxpzenlkujgmgkyaazczqracebdvewozmfwqrmdyfexgbjleztekjcbbqlbnbevcxuvglmblmbdhapfywlndyybynuykqrdjcyakgddflotdennunuqccytqposgaiouoaapigdbsmbotrd
zpquqwfyttblbazyjxqzdbzpibvadecgmusskjedbzjblhlnulkslomhatxjleoslcxokhdrgrqttbtrlcoafomxzpkhqtyyotzpozykcnuhdxswkxwdtxpseeirictakqomlouvvdbkuwbydkqunwfoxczhtgyxraiieapudazlfyjcmdsvlztdl
yicrgpivituhuwnszewcxhilpgcxturivvpelddnstkdjnfmriqiwmskegkshiiypntzplmoyalgtlclbfbjffvicoazgxncyobbemaosqgdnsflkqnwujljzsszdywdpwhopkvdhvgdyvdfxfwqnlrrmawqqfpvusoqnqfnuwkuepobhlqwajzpq
emqhaoczmdpfsqjwsnoirmxuikvzqncwycqlspnaldnzzwgkftanmssofwpmsnokzqwodbgtqjeoerkichxyzibiaxehyypxtzpoacdhzfvlxddooyvnbcgajkacishkjjqztcdkzcwomncszvxwjmlswsydpqbppnhcmttatiuqopcqofiqwkkbl
wuwykcwggvokvhefpkwfbhijoqrikgrsojgkcsaurqyvvpptpmllsleyltrspekttkfvjtonrdadzgtmqpfdnypjriqsvkvuufbjvablfuflvujfhgeroxfklgxhasenuivnahkwnikohpiqgnpeuv


*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define MAX_ALPHABETS 26
long long int scale = (long long int)(1000000007);
long long int countPalindrome(string input)
{
    vector<long long int> singleCount(MAX_ALPHABETS, (long long int )0);
    vector<long long int> palindromeCount(MAX_ALPHABETS, (long long int)0);
    vector< vector<long long int> > seqCount(MAX_ALPHABETS,vector<long long int> (MAX_ALPHABETS, (long long int)0));
    long long int result = 0;
    for (int i = 0; i < input.size(); i++)
    {
        int index = input[i] - 'a';// Gives the Index for accessing the chars.
        result += (palindromeCount[index]%scale);
        result  = result % scale;
        // Update all the arrays
        for (int j = 0; j < MAX_ALPHABETS;  j++)
        {
            palindromeCount[j] += (seqCount[j][index] );
            //palindromeCount[j] += (seqCount[j][index] % scale);
            //palindromeCount[j] = palindromeCount[j] % scale;
        }
        for (int j = 0; j < MAX_ALPHABETS; j++)
        {
            seqCount[j][index] += (singleCount[j]);
            //seqCount[j][index] += (singleCount[j] % scale);
            //seqCount[j][index] = seqCount[j][index]  % scale;
        }
        singleCount[index]++;
        //singleCount[index] = singleCount[index] % scale;
    }
    return result;
}
int main()
{
    string s;
    cin >> s;
    long long result =  countPalindrome(s);
    cout << result << endl;
    return 1;
}

