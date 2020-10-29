#include <bsm/libbsm.h>

#include <stdio.h>

#define STUB() printf("Stub %s called\n", __func__);

int audit_token_to_pidversion(audit_token_t atoken)
{
	STUB();
	return 0;
}

void *au_sdev_read_aia(void)
{
	STUB();
	return NULL;
}

void *au_sdev_open(void)
{
	STUB();
	return NULL;
}
