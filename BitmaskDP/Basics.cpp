#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;--i)
#define repn(i,n) for(int i=1;i<=n;++i)
#define rng(i, a, b) for(int i=a; i<b; i++)
#define gnr(i,a,b) for(int i=b-1;i>=a;--i)
#define vi vector<int>
#define vl vector<long long>
#define pi pair<int, int> 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mpr make_pair
 
using namespace std;

void yesno(bool a) {
    cout << (a?"YES\n":"NO\n");
}
 
int t, n;

// NEW TRICK 101 : TO FIND THE LEFT MOST SET BIT I.E 1110100 -> RETURNING 0000100 -> THIS CAN BE DONE BY X ^ (X & (X-1))
// THE DIFFERENCE OF TWO NUMBERS N - (N-1) IS ALL THE BITS ON RIGHTMOST ONE ARE FLIPPED INCLUDING THE RIGHTMOST ONE 0100 - 0001 -> 0011
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // check divisibility of a number x by 2 ^ k
    int x, k;
    cin >> x >> k;

    cout << ((x & ((1 << k) - 1))) << '\n'; // for ex check if a no. is even -> (x & 1);

    // ~x -> all bits are flipped
    // ~x = -x - 1
    cout << (~29) << ' ' << (~INT_MAX) << '\n'; // result will be -30

    // the left shift x << k appends k zero bits to the number ( x * (1 << k))
    // the right shift x >> k removes the last k bits from the number (x / (1 << k))
    cout << (14 << 2) << '\n'; // 14(1110) -> 56 111000 equivalent to 14 * 2 ^ 2
    cout << (49 >> 3) << '\n'; // 49(110001) -> 6(11) equivalent to 49 / 2 ^ 3


    // the property (1 << k) can be used to access the kth bit of the number
    // so to check if kth bit of number is set or not we can do & operation b/w number and kth bit
    // following code prints binary representing of a 32 bit integer

    per(i, 32) {
    	cout << ((x & (1 << i)?1:0)) << ' ';
    } cout << '\n';

    // it is also possible to change the kth bit using this property
    cout << (x | (1 << k)) << '\n'; // sets the kth bit to one
    cout << (x & ~(1 << k)) << '\n'; // sets the kth bit to zero
    cout << (x ^ (1 << k)) << '\n'; // flips the kth bit of the number
    cout << (x & (x - 1)) << '\n'; // sets the last one bit of x to zero
    // from the above point it can be noted that a number is a power of two exactly when
    // this is because powers of two only have one set bit and when we use x & (x-1) to unset this bit the number will become zero
    cout << ((x & (x-1)) == 0?"Power of Two":"Not a power of two") << '\n';
    cout << (x & (-x)) << '\n'; // sets all the bits of the number to zero
    cout << (x | (x - 1)) << '\n'; // inverts all the bits after the last one bit

    // Additional functions (C++)
   	int y = 5328; // 00000000000000000001010011010000
   	// 1. __builtin_clz(x) -> counts the # of zeroes in the beginning of the number
   	cout << __builtin_clz(y) << '\n'; // 19
   	// 2. __builtin_ctz(x) -> counts the # of zeroes in the end of the number
   	cout << __builtin_ctz(y) << '\n'; // 4
   	// 3. __builtin_popcount(x) -> counts the # of set bits in x (# of ones)
   	cout << __builtin_popcount(y) << '\n'; // 5
   	// 4. __builtin_parity(x) -> checks parity( even(0) or odd(1) number of ones)
   	cout << __builtin_parity(y) << '\n'; // 1

   	// use ll in the suffix to support long longs


   	// Representing Subsets
   	// Every subset of a set {0, 1, 2, ..., n-1} can be represented as a n bit integer whose set bits indicate which element is present in the set
   	// this is efficient as each element of the set requires only one set bit

   	// ex: {3, 4, 8} bit representation in 32 bits is 00000000000000000000000100011000

   	int Z = 0;
   	Z |= (1 << 3); // set the 4th bit for number 3
   	Z |= (1 << 4);
   	Z |= (1 << 8);

   	cout << __builtin_popcount(Z) << '\n';
   	// prints all the element in the set
   	rep(i, 32) {
   		if(Z & ( 1 << i)) cout << i << ' ';
   	}

   	// set operations
   	// a union b ~> a | b
   	// a intersection b ~> a & b
   	// a complement ~> ~a
   	// difference a / b ~> a & (~b)

   	// ex
   	int u = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8);
   	int v = (1 << 7) | (1 << 10);
    
   	cout << __builtin_popcount(u | v); // set union {1, 3, 4, 8, 7, 10};
    // COUNT THE NUMBER OF BIT CHANGES REQUIRED TO CHANGE A -> B FOR EXAMPLE A = 31(11111) B = 14(01100) ANS = 3;
    cout << __builtin_popcount(u ^ v); // number of bit changes required
   	// iterating through subsets
   	// iterating through all subsets of {0, 1, 2, ..., n-1} (i.e) (2 ^ n-1)

   	rep(i, (1 << n)) {
   		// process subsets
   	}

   	// iterating through subsets that have exactly t elements
   	rep(i, (1 << n)) {
   		if(__builtin_popcount(i) == t) {
   			// process
   		}
   	}

   	// alter way
   	int b = 0;
   	while(b = (b-x) & x) {
   		// process
   	}




}
