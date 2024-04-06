   #include <iostream>                                                                                                     
#include <cmath>
#include <string>                                                                                                       
using namespace std;
// p = 13, q = 61                                                                                                       
//

string caesar_cipher(const string& text, int shift) {
    string newtext = "";
    for (char c : text) {
        if (isalpha(c)) {                                                                                    
			char a = isupper(c) ? 'A' : 'a';
            newtext += static_cast<char>((c - a + shift) % 26 + a);                                                             
			} else {
            newtext += c;                                                                                                       
			}
    }                                                                                                                       
	return newtext;
}                                                                                                                       
//.                                                                                                                     
int calc(int b, int exp, int mod) {
    int result = 1;                                                                                                         
	while (exp > 0) {
        if (exp % 2 == 1) {                                                                                                         
		result = (result * b) % mod;
        }                                                                                                                       
		exp = exp / 2;
        b = (b * b) % mod;                                                                                                  
		}
	}
    return result;
}
int main() {                                                                                                              
    int p = 13;
	int q = 61;
    // Первый участник (Alice)
    int private_key_alice = 2;
    int public_key_alice = calc(q, private_key_alice, p);
    cout<<"публичный Ключ Алисы "<< public_key_alice<<endl;

    // Второй участник (Bob)
    int private_key_bob = 10;
    int public_key_bob = calc(q, private_key_bob, p);
    cout<<"публичный Ключ Боба "<<public_key_bob<<endl;

    // Обмен и вычисление общего секретного ключа
    int secret_bob = calc(public_key_alice, private_key_bob, p);

    // Боб пишет сообщение
    string plaintext = "Hi, Alice!";
    // Боб использует в качестве сдвига свой секретный ключ
    int shift = secret_bob;
    // Сообщение шифруется
    string ciphertext = caesar_cipher(plaintext, shift);
    // Сообщение отправляется
    cout << "Зашифрованный текст: " << ciphertext << endl;
    // Алиса вычисляет сдвиг
    int secret_alice = calc(public_key_bob, private_key_alice, p);

    string decrypted_text = caesar_cipher(ciphertext, 26 - secret_alice); // Расшифровка
    cout << "Расшифрованный текст: " << decrypted_text << endl;
    return 0;
}
