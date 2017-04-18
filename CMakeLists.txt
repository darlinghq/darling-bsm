project(bsm)

add_compile_options(
	-nostdinc
	-std=c99
)

add_definitions(

)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/openbsm)

set(DYLIB_INSTALL_NAME "/usr/lib/libbsm.0.dylib")
add_darling_library(bsm.0 SHARED
	openbsm/libbsm/bsm_audit.c
	openbsm/libbsm/bsm_class.c
	openbsm/libbsm/bsm_control.c
	openbsm/libbsm/bsm_domain.c
	openbsm/libbsm/bsm_event.c
	openbsm/libbsm/bsm_flags.c
	openbsm/libbsm/bsm_io.c
	openbsm/libbsm/bsm_mask.c
	openbsm/libbsm/bsm_notify.c
	openbsm/libbsm/bsm_socket_type.c
	openbsm/libbsm/bsm_token.c
	openbsm/libbsm/bsm_user.c
	openbsm/libbsm/bsm_wrappers.c
	openbsm/libbsm/bsm_errno.c
	openbsm/libbsm/bsm_fcntl.c
)
make_fat(bsm.0)
target_link_libraries(bsm.0 system)

install(TARGETS bsm.0 DESTINATION libexec/darling/usr/lib)
InstallSymlink(libbsm.0.dylib libexec/darling/usr/lib/libbsm.dylib)

install(FILES
	openbsm/libbsm/au_class.3
	openbsm/libbsm/au_control.3
	openbsm/libbsm/au_domain.3
	openbsm/libbsm/au_errno.3
	openbsm/libbsm/au_event.3
	openbsm/libbsm/au_fcntl_cmd.3
	openbsm/libbsm/au_free_token.3
	openbsm/libbsm/au_io.3
	openbsm/libbsm/au_mask.3
	openbsm/libbsm/au_open.3
	openbsm/libbsm/au_socket_type.3
	openbsm/libbsm/au_token.3
	openbsm/libbsm/au_user.3
	openbsm/libbsm/audit_submit.3
	openbsm/libbsm/libbsm.3

	DESTINATION libexec/darling/usr/share/man/man3
)

install(FILES
	openbsm/man/audit.log.5
	openbsm/man/audit_class.5
	openbsm/man/audit_control.5
	openbsm/man/audit_event.5
	openbsm/man/audit_user.5
	openbsm/man/audit_warn.5

	DESTINATION libexec/darling/usr/share/man/man5
)
