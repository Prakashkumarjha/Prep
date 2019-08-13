#include<iostream>
using namespace std;

void kmp(string str1,string pat)
{
	int lps[pat.length()+1];
	//cout<<pat.length()<<endl<<endl;
	int k=1;
	int l=0;
	lps[0]=0;
	while(k<pat.length())
	{
		if (pat[k]==pat[l])
		{
			lps[k]=l+1;
			k++;
			l++;
		}
		else if(l==0 && pat[k]!=pat[l])
		{
			k++;
		}
		else if(pat[k]!=pat[l])
		{
			l=0;
		}
		
	}

	int i=0;
	int j=0;
	while(i<str1.length())
	{
	
		if(str1[i]==pat[j])
		{
			//cout<<i<<"     "<<str1[i]<<".     "<<j<<"    "<<pat[j]<<endl;
			i++;
			j++;
		}
		if(j==pat.length())
		{
			//return
			int p=i-j;
			cout<<p<<endl;
			//count++;
			j=lps[j-1];

		}

		else if(pat[j]!=str1[i])
		{
			if(j!=0)
				j=lps[j-1];
			else
				i++;
			//j=lps[j-1];
		}
	}
	//return count;
}
int main()
{
	string str1="ABABDABACDABABCABAB";
	string pat="ABABCABAB";
	kmp(str1,pat);
	//cout<<kmp(str1,pat,0)<<endl;
}
// #include <iostream>
// using namespace std; 

// void computeLPSArray(char* pat, int M, int* lps); 


// void KMPSearch(char* pat, char* txt) 
// { 
// 	int M = strlen(pat); 
// 	int N = strlen(txt); 

// 	int lps[M]; 

// 	computeLPSArray(pat, M, lps); 

// 	int i = 0; 
// 	int j = 0; 
// 	while (i < N) { 
// 		if (pat[j] == txt[i]) { 
// 			j++; 
// 			i++; 
// 		} 

// 		if (j == M) { 
// 			cout<<"Found pattern at index "<< i - j; 
// 			j = lps[j - 1]; 
// 		} 

// 		else if (i < N && pat[j] != txt[i]) { 
// 			if (j != 0) 
// 				j = lps[j - 1]; 
// 			else
// 				i = i + 1; 
// 		} 
// 	} 
// } 

// void computeLPSArray(char* pat, int M, int* lps) 
// { 
	
// 	int len = 0; 

// 	lps[0] = 0; 

// 	int i = 1; 
// 	while (i < M) { 
// 		if (pat[i] == pat[len]) { 
// 			len++; 
// 			lps[i] = len; 
			 
// 			i++; 
// 		} 
// 		else 
// 		{ 
// 			if (len != 0) { 
// 				len = lps[len - 1]; 

// 				} 
// 			else 
// 			{ 
// 				lps[i] = 0; 
// 				cout<<"Lps["<<i<<"]:-"<<lps[i]<<endl;
// 				i++; 
// 			} 
// 		} 
// 	}
//   for(int i=0;i<M;i++)
//   {
//     //cout<<"Lps["<<i<<"]:-"<<lps[i]<<endl;
//   }
// } 

// int main() 
// { 
// 	char txt[] = "ABABDABACDABABCABAB"; 
// 	char pat[] = "ABABCABAB"; 
// 	KMPSearch(pat, txt); 
// 	return 0; 
// } 