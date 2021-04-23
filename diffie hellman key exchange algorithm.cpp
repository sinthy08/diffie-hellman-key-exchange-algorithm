//Umme Kawser Sinthia


#include<bits/stdc++.h>
using namespace std;

long long int q, alpha, alicePublicKey, alicePrivateKey, bobPublicKey, bobPrivateKey, aliceSharedKey_Ka, bobSharedKey_Kb;

long long int CalculateKey (long long int a, long long int power, long long int q);
void ClientOne();
void ClientTwo();
void SharedKey();


int main()
{

    cout << "Enter the value of prime number (q) : ";
	cin >> q ;

	cout << "Enter the primitive root modulo value (Alpha) : ";
	cin >> alpha ;
	cout << endl;

	ClientOne();
	ClientTwo();
	SharedKey();


	return 0;
}


long long int CalculateKey(long long int a, long long int power, long long int q)
{
    // CalculateKey function to return value of a^power mod q
	long long int temp = a;

    while ( --power )      // power-1 times execution of loop for multiplying in number of the power
    {
        temp *= a;         // Y ^ ax
        temp %= q;        //mod of (Y^ax)
    }

    return temp ;

}



void ClientOne ()
{
    //A random private key will be generated for Alice or client 1
    srand (time(NULL));
    alicePrivateKey = rand() % 1000 + 1;
	cout << "The randomly selected private key for Client 1 : " << alicePrivateKey << endl;

	alicePublicKey = CalculateKey(alpha, alicePrivateKey, q); // gets the generated key

}


void ClientTwo ()
{
    //A random private key will be generated for Bob or client 2
    bobPrivateKey = rand() % 1000 + 1;
	cout << "The randomly selected private key for Client 2 : " << bobPrivateKey << endl << endl ;

	bobPublicKey = CalculateKey(alpha, bobPrivateKey, q); // gets the generated key based on the

}

void SharedKey()
{
    //Calculating the shared secret key between two clients
    aliceSharedKey_Ka = CalculateKey(bobPublicKey, alicePrivateKey, q); // Secret key for Alice
	bobSharedKey_Kb = CalculateKey(alicePublicKey, bobPrivateKey, q); // Secret key for Bob

	cout << "Shared Secret key for Client 1 is : " << aliceSharedKey_Ka << endl;
	cout << "Shared Secret Key for Client 2 is : " << bobSharedKey_Kb << endl;

}


