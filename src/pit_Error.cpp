#include "stdafx.h"
#include "pit_ERROR.h"
#ifdef _WIN32
#include <windows.h>
char* convertWindowsError(int error) {
	switch (error) {
	case ERROR_INVALID_PARAMETER:
		return (char*)"Invalid Parameters";

	case STATUS_ACCESS_VIOLATION:
		return (char*)"ACCESS VIOLATION";
	case ERROR_TIMEOUT:
		return (char*)"Timed out";
	case ERROR_NOT_READY:
		return (char*)"Not ready";
	}
	return (char*)"Unkown Error";
}
#endif // DEBUG

char* convertSystemError(int error) {
#ifdef _WIN32
	return convertWindowsError(error);
#endif // __WIN32
	return (char*)"nfkdsldfbloqbklbsdfolbfasdofeoufbvousdbfkjhb zxccjhkbjk sdzbcil;ksdfvsyiufv;zl";
}

char* ErrorType(int error) {
	char* type;
	switch (error) {
	case ERR_NONE:
		type = (char*)"Not an Error"; break;
	case ERR_OUT_OF_BOUND:
		type = (char*)"Out of Bounds Error"; break;
	case ERR_FAILED_INIT:
		type = (char*)"Failed to Initializes some system"; break;
	case ERR_TOUCH_FAIL:
		type = (char*)"Touch injection error"; break;
#ifdef isDebug
	case ERR_NOT_DEFINED_YET:
		type = (char*)"Function not yet defined"; break;
#endif
	default:
		type = (char*)"Unknown Error"; break;
	}
	return type;
}
