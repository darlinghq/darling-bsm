#include <bsm/libbsm.h>
#include <bsm/audit_session.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#define STUB() printf("Stub %s called\n", __func__);

int audit_token_to_pidversion(audit_token_t atoken)
{
	STUB();
	return 0;
}

int au_sdev_read_aia(au_sdev_handle_t* ash, int* event, auditinfo_addr_t* aia_p) {
	if (!ash || !event || !aia_p) {
		// i'm assuming this is what we should return
		errno = EINVAL;
		return -1;
	}

	// this function is a stub that pretends there is nothing to read from the device,
	// so we either return EWOULDBLOCK if we were told to be non-blocking, or we block forever

	if (((uintptr_t)ash->ash_fp) & AU_SDEVF_NONBLOCK) {
		errno = EWOULDBLOCK;
		return -1;
	}

	// block forever
	// `pause` might wakeup on signals, so wrap it in a loop
	while (1) {
		pause();
	};

	return 0;
};

au_sdev_handle_t* au_sdev_open(int flags) {
	au_sdev_handle_t* ash = malloc(sizeof(au_sdev_handle_t));
	if (ash == NULL) {
		// not sure if this is the right error code
		errno = EAGAIN;
		return NULL;
	}

	ash->ash_buf = NULL;
	ash->ash_reclen = 0;
	ash->ash_bytesread = 0;

	// we're just a stub; we don't actually open an fd, so let's keep our flags there
	// we'll use it later on to determine whether to be blocking or not
	ash->ash_fp = (uintptr_t)flags;

	return ash;
};
