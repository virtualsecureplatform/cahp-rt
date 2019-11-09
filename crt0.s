.global _start
_start:
	# The initial value of SP is the end of the RAM.
	li sp, 0x200-2

	jsal main
	js 0
