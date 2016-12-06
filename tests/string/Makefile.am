AUTOMAKE_OPTIONS = dejagnu
strcmp = strcmp_eq strcmp_noeq_diff_length strcmp_noeq_diff_length_backwards strcmp_noeq_same_length
strcpy = strcpy_normal
strchr = strchr_true strchr_false
memcmp = memcmp_zero memcmp_true memcmp_false
memcpy = memcpy_zero memcpy_ten
memset = memset_zero
check_PROGRAMS = $(strcmp) $(strcpy) $(strchr) $(memcmp) $(memcpy) $(memset)
TESTS = $(check_PROGRAMS)
all:
