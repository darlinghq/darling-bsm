#include <bsm/libbsm.h>

#include <stdio.h>

#define STUB() printf("Stub %s called\n", __func__);

uid_t audit_token_to_auid(audit_token_t atoken)
{
	STUB();
	return 0;
}

uid_t audit_token_to_euid(audit_token_t atoken)
{
	STUB();
	return 0;
}

gid_t audit_token_to_egid(audit_token_t atoken)
{
	STUB();
	return 0;
}

uid_t audit_token_to_ruid(audit_token_t atoken)
{
	STUB();
	return 0;
}

gid_t audit_token_to_rgid(audit_token_t atoken)
{
	STUB();
	return 0;
}

/* Not needed?
pid_t audit_token_to_pid(audit_token_t atoken)

{
	STUB();
	return 0;
}
*/

au_asid_t audit_token_to_asid(audit_token_t atoken)
{
	STUB();
	return 0;
}

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
