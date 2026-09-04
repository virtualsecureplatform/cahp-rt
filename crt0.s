.global _start
_start:
	# RAM is a power-of-two circular address space.  -2 selects its last
	# 16-bit word for every configured RAM address width.
	li sp, -2
	lw sp, 0(sp)
	lw a0, 0(sp)	# argc
	addi a1, sp, 2	# argv

	jsal main
	hlt
