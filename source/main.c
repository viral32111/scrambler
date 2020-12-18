/**********************************************************************
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>
**********************************************************************/

// include required headers
#include <stdio.h> // printf, size_t
#include <stdlib.h> // malloc
#include <string.h> // strlen

// magic
char *crypt( const char *message, const size_t message_length, const char *password, const size_t password_length ) {
	// allocate memory for storing the result, same length as original message
	char *result = malloc( message_length );

	// scramble the message using xor
	for ( int i = 0; i < message_length; i++ ) result[ i ] = message[ i ] ^ password[ i % password_length ];

	// null terminate the result
	result[ message_length ] = '\0';

	// return the result
	return result;
}

// entry point
int main() {
	// create the message & password
	const char *message = "hello, how are you doing?"; // nt
	const char *password = "N9HKq3k3n3QbBqBnruYrWBDpB9JU5nn8"; // nt

	// store the length of the message & password
	const size_t message_length = strlen( message ); // without nt
	const size_t password_length = strlen( password ); // without nt

	// do some fancy math
	char *message_encrypted = crypt( message, message_length, password, password_length );
	char *message_decrypted = crypt( message_encrypted, message_length, password, password_length );

	// output starting values
	printf( "Message: '%s'\n", message );
	printf( "Password: '%s'\n", password );

	// output the encrypted message in hexadecimal
	printf( "Encrypted: '" );
	for ( int i = 0; i < message_length; i++ ) printf( "%02X", message_encrypted[ i ] );
	printf( "'\n" );

	// output the decrypted message
	printf( "Decrypted: '%s'\n", message_decrypted );

	// free memory
	free( message_encrypted );
	free( message_decrypted );

	// we good
	return 0;
}
