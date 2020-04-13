.global _start
_start:
	li sp, 0x200-2
	lw sp, 0(sp)
	lw a0, 0(sp)	# argc
	addi a1, sp, 2	# argv

	jsal main
	hlt
