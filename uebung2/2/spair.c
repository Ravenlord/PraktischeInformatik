/**
 * Self forking full-duplex program.
 *
 * AUTHOR: Richard Fussenegger
 * AUTHOR: Markus Deutschl
 * LINK: http://beej.us/guide/bgipc/output/html/multipage/unixsock.html
 */

#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	/** Our socket pair. */
	int sv[2];
	/** Buffer for data exchange. */
	char buf;
	/** Ignore return values of write and read. */
	int ignoreme;

	if (socketpair(AF_UNIX, SOCK_STREAM, 0, sv) == -1) {
		perror("socketpair");
		exit(-1);
	}

	// Our child process.
	if (!fork()) {
		ignoreme = read(sv[1], &buf, 1);
		printf("child: read '%c'\n", buf);
		buf = toupper(buf);
		ignoreme = write(sv[1], &buf, 1);
		printf("child: sent '%c'\n", buf);
	}
	// Our parent process.
	else {
		ignoreme = write(sv[0], "x", 1);
		printf("parent: sent 'x'\n");
		ignoreme = read(sv[0], &buf, 1);
		printf("parent: read '%c'\n", buf);
		// The nightmare of any parent.
		wait(NULL);
	}

	// Eat that gcc! :D
	ignoreme = 0;
	return ignoreme;
}
