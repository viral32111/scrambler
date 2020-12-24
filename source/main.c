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
#include "algorithms/xor.h"

// entry point
int main( int argc, char *argv[] ) {

	// arg check
	if ( argc != 3 ) {
		printf( "u used me wrong, dumbass\n\nusage: %s <algorithm> '<message>'\nexample: %s xor 'hello world'\n", argv[ 0 ], argv[ 0 ] );
		return 1;
	}

	// lmao ignore the algo arg (for now, until more algos are implemented)

	// output
	printf( "algorithm: %s\nmessage: %s\n", argv[ 1 ], argv[ 2 ] );

	// get passphrase from user
	char passphrase[ 128 ]; // fuck people who want passphrases over 128 characters
	printf( "passphrase: " );
	scanf( "%[^\n]", passphrase );

	// store the length of the message & passphrase
	const size_t message_length = strlen( argv[ 2 ] ); // without nt
	const size_t passphrase_length = strlen( passphrase ); // without nt

	// do some fancy math
	char *message_encrypted = xor_crypt( argv[ 2 ], message_length, passphrase, passphrase_length );

	// output the encrypted message in hexadecimal
	printf( "result: " );
	for ( int i = 0; i < message_length; i++ ) printf( "%02X ", message_encrypted[ i ] );
	printf( "\n" );

	// free memory
	free( message_encrypted );

	// we good
	return 0;
}
