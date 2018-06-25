;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.0 #9615 (MINGW64)
;--------------------------------------------------------
	.module circular_buffer
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _mask_PARM_2
	.globl _pop_PARM_2
	.globl _push_PARM_2
	.globl _size
	.globl _empty
	.globl _full
	.globl _mask
	.globl _push
	.globl _pop
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_push_PARM_2:
	.ds 1
_push_buf_1_15:
	.ds 3
_pop_PARM_2:
	.ds 3
_pop_buf_1_17:
	.ds 3
_pop_sloc0_1_0:
	.ds 3
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
_mask_PARM_2:
	.ds 1
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'size'
;------------------------------------------------------------
;buf                       Allocated to registers r5 r6 r7 
;------------------------------------------------------------
;	circular_buffer.c:5: uint8_t size(CircularBuffer_t *buf) {
;	-----------------------------------------
;	 function size
;	-----------------------------------------
_size:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
;	circular_buffer.c:6: return (buf->writeIndex - buf->readIndex);
	mov	a,#0x04
	add	a,r5
	mov	r2,a
	clr	a
	addc	a,r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	mov	a,#0x03
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	a,r2
	clr	c
	subb	a,r5
	mov	dpl,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'empty'
;------------------------------------------------------------
;buf                       Allocated to registers r5 r6 r7 
;------------------------------------------------------------
;	circular_buffer.c:9: bool empty(CircularBuffer_t *buf) {
;	-----------------------------------------
;	 function empty
;	-----------------------------------------
_empty:
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
;	circular_buffer.c:10: return (buf->readIndex == buf->writeIndex);
	mov	a,#0x03
	add	a,r5
	mov	r2,a
	clr	a
	addc	a,r6
	mov	r3,a
	mov	ar4,r7
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r2,a
	mov	a,#0x04
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	a,r2
	cjne	a,ar5,00103$
	setb	c
	ret
00103$:
	clr	c
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'full'
;------------------------------------------------------------
;buf                       Allocated to registers r5 r6 r7 
;------------------------------------------------------------
;	circular_buffer.c:13: bool full(CircularBuffer_t *buf) {
;	-----------------------------------------
;	 function full
;	-----------------------------------------
_full:
;	circular_buffer.c:14: return size(buf) == buf->maxBufferLength;
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
	push	ar7
	push	ar6
	push	ar5
	lcall	_size
	mov	r4,dpl
	pop	ar5
	pop	ar6
	pop	ar7
	mov	a,#0x05
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r5,a
	mov	a,r4
	cjne	a,ar5,00103$
	setb	c
	ret
00103$:
	clr	c
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'mask'
;------------------------------------------------------------
;val                       Allocated with name '_mask_PARM_2'
;buf                       Allocated to registers r5 r6 r7 
;------------------------------------------------------------
;	circular_buffer.c:17: uint8_t mask(CircularBuffer_t *buf, uint8_t val) {
;	-----------------------------------------
;	 function mask
;	-----------------------------------------
_mask:
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
;	circular_buffer.c:18: return val & (buf->maxBufferLength - 1);
	mov	a,#0x05
	add	a,r5
	mov	r5,a
	clr	a
	addc	a,r6
	mov	r6,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	dec	a
	anl	a,_mask_PARM_2
	mov	dpl,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'push'
;------------------------------------------------------------
;data                      Allocated with name '_push_PARM_2'
;buf                       Allocated with name '_push_buf_1_15'
;------------------------------------------------------------
;	circular_buffer.c:21: bool push(CircularBuffer_t *buf, uint8_t data) {
;	-----------------------------------------
;	 function push
;	-----------------------------------------
_push:
;	circular_buffer.c:22: if(full(buf))
	mov	_push_buf_1_15,dpl
	mov	(_push_buf_1_15 + 1),dph
	mov	(_push_buf_1_15 + 2),b
	lcall	_full
	jnc	00102$
;	circular_buffer.c:23: return false;
	clr	c
	ret
00102$:
;	circular_buffer.c:25: buf->array[mask(buf, buf->writeIndex++)] = data;
	mov	dpl,_push_buf_1_15
	mov	dph,(_push_buf_1_15 + 1)
	mov	b,(_push_buf_1_15 + 2)
	lcall	__gptrget
	mov	r2,a
	inc	dptr
	lcall	__gptrget
	mov	r3,a
	inc	dptr
	lcall	__gptrget
	mov	r4,a
	mov	a,#0x04
	add	a,_push_buf_1_15
	mov	r0,a
	clr	a
	addc	a,(_push_buf_1_15 + 1)
	mov	r1,a
	mov	r7,(_push_buf_1_15 + 2)
	mov	dpl,r0
	mov	dph,r1
	mov	b,r7
	lcall	__gptrget
	mov	r6,a
	inc	a
	mov	dpl,r0
	mov	dph,r1
	mov	b,r7
	lcall	__gptrput
	mov	_mask_PARM_2,r6
	mov	dpl,_push_buf_1_15
	mov	dph,(_push_buf_1_15 + 1)
	mov	b,(_push_buf_1_15 + 2)
	push	ar4
	push	ar3
	push	ar2
	lcall	_mask
	mov	r7,dpl
	pop	ar2
	pop	ar3
	pop	ar4
	mov	a,r7
	add	a,r2
	mov	r2,a
	clr	a
	addc	a,r3
	mov	r3,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,_push_PARM_2
	lcall	__gptrput
;	circular_buffer.c:26: return true;
	setb	c
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'pop'
;------------------------------------------------------------
;data                      Allocated with name '_pop_PARM_2'
;buf                       Allocated with name '_pop_buf_1_17'
;sloc0                     Allocated with name '_pop_sloc0_1_0'
;------------------------------------------------------------
;	circular_buffer.c:29: bool pop(CircularBuffer_t *buf, uint8_t *data) {
;	-----------------------------------------
;	 function pop
;	-----------------------------------------
_pop:
;	circular_buffer.c:30: if(empty(buf))
	mov	_pop_buf_1_17,dpl
	mov	(_pop_buf_1_17 + 1),dph
	mov	(_pop_buf_1_17 + 2),b
	lcall	_empty
	jnc	00102$
;	circular_buffer.c:31: return false;
	clr	c
	ret
00102$:
;	circular_buffer.c:33: *data = buf->array[mask(buf, buf->readIndex++)];
	mov	r2,_pop_PARM_2
	mov	r3,(_pop_PARM_2 + 1)
	mov	r4,(_pop_PARM_2 + 2)
	mov	dpl,_pop_buf_1_17
	mov	dph,(_pop_buf_1_17 + 1)
	mov	b,(_pop_buf_1_17 + 2)
	lcall	__gptrget
	mov	_pop_sloc0_1_0,a
	inc	dptr
	lcall	__gptrget
	mov	(_pop_sloc0_1_0 + 1),a
	inc	dptr
	lcall	__gptrget
	mov	(_pop_sloc0_1_0 + 2),a
	mov	a,#0x03
	add	a,_pop_buf_1_17
	mov	r5,a
	clr	a
	addc	a,(_pop_buf_1_17 + 1)
	mov	r6,a
	mov	r7,(_pop_buf_1_17 + 2)
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r1,a
	inc	a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrput
	mov	_mask_PARM_2,r1
	mov	dpl,_pop_buf_1_17
	mov	dph,(_pop_buf_1_17 + 1)
	mov	b,(_pop_buf_1_17 + 2)
	push	ar4
	push	ar3
	push	ar2
	lcall	_mask
	mov	r7,dpl
	pop	ar2
	pop	ar3
	pop	ar4
	mov	a,r7
	add	a,_pop_sloc0_1_0
	mov	r7,a
	clr	a
	addc	a,(_pop_sloc0_1_0 + 1)
	mov	r6,a
	mov	r5,(_pop_sloc0_1_0 + 2)
	mov	dpl,r7
	mov	dph,r6
	mov	b,r5
	lcall	__gptrget
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrput
;	circular_buffer.c:34: return true;
	setb	c
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
