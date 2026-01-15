#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long op = 0;
int MD = 0;

void complexRec(int n , int dep) {
    MD = max(MD,dep);

   if (n <= 2) {
   	 	op++;
       return;
   }
  


   int p = n;
   while (p > 0) {
   		
       vector<int> temp(n);
       
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
           op+=1;
       }
       p >>= 1;
       
   }
   op++;


   vector<int> small(n);

   for (int i = 0; i < n; i++) {
       small[i] = i * i;
       op++;
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
       op+=n;
   } else {
       reverse(small.begin(), small.end());
       op+=n;
   }
   


   complexRec(n / 2, dep+1);
   complexRec(n / 2, dep+1);
   complexRec(n / 2, dep+1);
};
int main(){
	vector<int>  a= {1024,2048,4096,8192,16384};
    vector<int>  test;
    for (int i = 0; i < a.size(); i++) {
        test.push_back(a[i]);
    }

    int MD = 0;
	for (int n : test) {
        op = 0;
        MD = 0;
        auto start = high_resolution_clock::now();
        complexRec(n,1);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        
	cout << "n = " << n<< " ops = " << op<<" time(ms) = " << duration.count()<< " maxDepth = " << MD<< endl;
}
}
// T(n) = 3T(n/2) + nlogn + n + n 
//
// Time complexity = O(n^1.58)
