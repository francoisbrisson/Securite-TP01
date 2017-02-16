#include <iostream>
#include <windows.h>
#include "sha512.h"

//Pas besoin de cette méthode d'encryption pour la solution finale
//void Encrypt(std::string&);
std::string Decrypt(std::string str);
// Mot de passe: decakeisalie
int main()
{
	std::string message1 = "Jsywj%qj%rty%ij%ufxxj";
	std::string message2 = "Gts%rty%ij%ufxxj";
	std::string message3 = "Rfz{fnx%rty%ij%ufxxj";

	if (IsDebuggerPresent())
		return 0;
	else
	{
		std::string mdp;
		std::cout << Decrypt(message1) << std::endl;
		std::getline(std::cin, mdp);

		if (sha512(mdp+"E1F53135E559C253") == "69305b74c2a413b8c3c9ae8ba81ada6ee3ed0b360bd18ea0c9031ed4e3c1e199afed1dd4787780acb0825eb15bcf8191889551cc6c72f4fab73238cb4fb17a32")
			std::cout << Decrypt(message2) << std::endl;
		else
			std::cout << Decrypt(message3) << std::endl;
	}

	system("pause");
}


//void Encrypt(std::string &str)
//{
//	int len = str.length();
//	char a;
//	std::string strFinal(str);
//
//	for (int i = 0; i <= (len - 1); i++)
//	{
//		a = str.at(i);
//		int b = static_cast<int>(a); //get the ASCII value of 'a'
//		b += 5; //Mulitply the ASCII value by 2
//		if (b > 254) { b = 254; }
//		a = static_cast<char>(b);
//		strFinal.insert(i, 1, a);
//	}
//	std::string strEncrypted(strFinal, 0, len);
//	str = strEncrypted;
//}

std::string Decrypt(std::string str)
{
	int len = str.length();
	char a;
	std::string strFinal(str);

	for (int i = 0; i <= (len - 1); i++)
	{
		a = str.at(i);
		int b = static_cast<int>(a);
		b -= 5;

		a = static_cast<char>(b);
		strFinal.insert(i, 1, a);
	}
	std::string strDecrypted(strFinal, 0, len);
	return strDecrypted;
}