#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    // store the uids
    uid_t ruid = getuid();
    uid_t euid = geteuid();
    // store the gids
    gid_t rgid = getgid();
    gid_t egid = getegid();

    printf("Before execution UID: %d and EUID: %d\n", ruid, euid);
    printf("Before execution GID: %d and EGID: %d\n", rgid, egid);

    // elevate the privileges
    setuid(euid);
    setgid(egid);

    // perform action
    system("/bin/bash get_in.sh");

    // drop privileges
    if (setuid(ruid)) {
        fprintf(stderr, "Drop user privileges setuid(%d) failed!\n", ruid);
    }
    if (setgid(rgid)) {
        fprintf(stderr, "Drop group privileges setgid(%d) failed!\n", rgid);
    }

    printf("After execution UID: %d and EUID: %d\n", getuid(), geteuid());
    printf("After execution GID: %d and EGID: %d\n", getgid(), getegid());
    printf("Completed! Check output in /tmp/output\n");
    return 0;
}