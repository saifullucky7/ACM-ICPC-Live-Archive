#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>
#include<map>
#include<set>
#include<string>
#include<cstring>
#include<cstdio>
#include<stack>
#include<queue>
#include<math.h>
#include <utility>
#include <sstream> 
#include<bitset>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

typedef long long ll;
typedef std::vector<ll> vi;

#define PI acos(-1)
#define E 2.718281828459

std::bitset<2250> bs; // 10^7 + small extra bits should be enough for most prime-related problems
std::vector<ll> primes; // compact list of primes in form of vector<int>
void sieve(ll upperbound) { // create list of primes in [0 .. upperbound]
          int sieve_size = upperbound + 1; // add 1 to include upperbound
           bs.reset(); bs.flip(); // set all numbers to 1
            bs.set(0, false); bs.set(1, false); // except index 0 and 1
          for (ll i = 2; i <= sieve_size; i++) if (bs.test((size_t)i)) {
// cross out multiples of i starting from i * i! 
          for (ll j = i * i; j <= sieve_size; j += i) bs.set((size_t)j, false);
           primes.push_back((int)i);
    }
} 
vi primeFactors(ll N) {
      vi factors;          // vi "primes" (generated by sieve) is optional
      ll PF_idx = 0, PF = primes[PF_idx]; // using PF = 2, 3, 4, ..., is also ok.
      while ((PF * PF <= N)) { // stop at sqrt(N), but N can get smaller
        while (N % PF == 0) { 
		N /= PF; factors.push_back(PF); } // remove this PF
            PF = primes[++PF_idx]; // only consider primes!
            }
          if (N != 1) factors.push_back(N); // special case if N is actually a prime
      return factors;
}
int gcd(int a, int b)
{ 
       return (b == 0 ? a : gcd(b, a % b)); 
}

int main(int argc, char** argv) {
	//freopen("c.txt","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<int> a(n);
		vector<int>::iterator it;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		a[m]*=-1;
		int count=0;
		int i=0;
		bool found=false;
		while(true)
		{
			//cout<<"front "<<a[i]<<endl;
			int c=0;
			it=find(a.begin(),a.end(),a[i]);
			if(a[i]<0)
			{
				for(int j=i+1;j<a.size();j++)
			   { 
				if(a[j]>abs(a[i]))
				{
					c=1;
					int temp=*it;
					a.erase(it);
					a.push_back(temp);
					break;
				}
			   }  
			   if(c==0)
			  {  
				count++;
				a.erase(it);
				found=true;
				break;
			  }
			}
			else
			{
				
			for(int j=i+1;j<a.size();j++)
			{
				if(abs(a[j])>a[i])
				{
					c=1;
					int temp=*it;
					a.erase(it);
					a.push_back(temp);
					break;
				}
			}
			if(c==0)
			{
				count++;
				a.erase(it);
			}
		}
			//i++;
			
		}
		cout<<count<<endl;
	}
   return 0;
}
