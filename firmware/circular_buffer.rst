                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.6.0 #9615 (MINGW64)
                                      4 ;--------------------------------------------------------
                                      5 	.module circular_buffer
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _mask_PARM_2
                                     12 	.globl _pop_PARM_2
                                     13 	.globl _push_PARM_2
                                     14 	.globl _size
                                     15 	.globl _empty
                                     16 	.globl _full
                                     17 	.globl _mask
                                     18 	.globl _push
                                     19 	.globl _pop
                                     20 ;--------------------------------------------------------
                                     21 ; special function registers
                                     22 ;--------------------------------------------------------
                                     23 	.area RSEG    (ABS,DATA)
      000000                         24 	.org 0x0000
                                     25 ;--------------------------------------------------------
                                     26 ; special function bits
                                     27 ;--------------------------------------------------------
                                     28 	.area RSEG    (ABS,DATA)
      000000                         29 	.org 0x0000
                                     30 ;--------------------------------------------------------
                                     31 ; overlayable register banks
                                     32 ;--------------------------------------------------------
                                     33 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                         34 	.ds 8
                                     35 ;--------------------------------------------------------
                                     36 ; internal ram data
                                     37 ;--------------------------------------------------------
                                     38 	.area DSEG    (DATA)
      00005C                         39 _push_PARM_2:
      00005C                         40 	.ds 1
      00005D                         41 _push_buf_1_15:
      00005D                         42 	.ds 3
      000060                         43 _pop_PARM_2:
      000060                         44 	.ds 3
      000063                         45 _pop_buf_1_17:
      000063                         46 	.ds 3
      000066                         47 _pop_sloc0_1_0:
      000066                         48 	.ds 3
                                     49 ;--------------------------------------------------------
                                     50 ; overlayable items in internal ram 
                                     51 ;--------------------------------------------------------
                                     52 	.area	OSEG    (OVR,DATA)
                                     53 	.area	OSEG    (OVR,DATA)
                                     54 	.area	OSEG    (OVR,DATA)
      00007B                         55 _mask_PARM_2:
      00007B                         56 	.ds 1
                                     57 ;--------------------------------------------------------
                                     58 ; indirectly addressable internal ram data
                                     59 ;--------------------------------------------------------
                                     60 	.area ISEG    (DATA)
                                     61 ;--------------------------------------------------------
                                     62 ; absolute internal ram data
                                     63 ;--------------------------------------------------------
                                     64 	.area IABS    (ABS,DATA)
                                     65 	.area IABS    (ABS,DATA)
                                     66 ;--------------------------------------------------------
                                     67 ; bit data
                                     68 ;--------------------------------------------------------
                                     69 	.area BSEG    (BIT)
                                     70 ;--------------------------------------------------------
                                     71 ; paged external ram data
                                     72 ;--------------------------------------------------------
                                     73 	.area PSEG    (PAG,XDATA)
                                     74 ;--------------------------------------------------------
                                     75 ; external ram data
                                     76 ;--------------------------------------------------------
                                     77 	.area XSEG    (XDATA)
                                     78 ;--------------------------------------------------------
                                     79 ; absolute external ram data
                                     80 ;--------------------------------------------------------
                                     81 	.area XABS    (ABS,XDATA)
                                     82 ;--------------------------------------------------------
                                     83 ; external initialized ram data
                                     84 ;--------------------------------------------------------
                                     85 	.area XISEG   (XDATA)
                                     86 	.area HOME    (CODE)
                                     87 	.area GSINIT0 (CODE)
                                     88 	.area GSINIT1 (CODE)
                                     89 	.area GSINIT2 (CODE)
                                     90 	.area GSINIT3 (CODE)
                                     91 	.area GSINIT4 (CODE)
                                     92 	.area GSINIT5 (CODE)
                                     93 	.area GSINIT  (CODE)
                                     94 	.area GSFINAL (CODE)
                                     95 	.area CSEG    (CODE)
                                     96 ;--------------------------------------------------------
                                     97 ; global & static initialisations
                                     98 ;--------------------------------------------------------
                                     99 	.area HOME    (CODE)
                                    100 	.area GSINIT  (CODE)
                                    101 	.area GSFINAL (CODE)
                                    102 	.area GSINIT  (CODE)
                                    103 ;--------------------------------------------------------
                                    104 ; Home
                                    105 ;--------------------------------------------------------
                                    106 	.area HOME    (CODE)
                                    107 	.area HOME    (CODE)
                                    108 ;--------------------------------------------------------
                                    109 ; code
                                    110 ;--------------------------------------------------------
                                    111 	.area CSEG    (CODE)
                                    112 ;------------------------------------------------------------
                                    113 ;Allocation info for local variables in function 'size'
                                    114 ;------------------------------------------------------------
                                    115 ;buf                       Allocated to registers r5 r6 r7 
                                    116 ;------------------------------------------------------------
                                    117 ;	circular_buffer.c:5: uint8_t size(CircularBuffer_t *buf) {
                                    118 ;	-----------------------------------------
                                    119 ;	 function size
                                    120 ;	-----------------------------------------
      0007E0                        121 _size:
                           000007   122 	ar7 = 0x07
                           000006   123 	ar6 = 0x06
                           000005   124 	ar5 = 0x05
                           000004   125 	ar4 = 0x04
                           000003   126 	ar3 = 0x03
                           000002   127 	ar2 = 0x02
                           000001   128 	ar1 = 0x01
                           000000   129 	ar0 = 0x00
      0007E0 AD 82            [24]  130 	mov	r5,dpl
      0007E2 AE 83            [24]  131 	mov	r6,dph
      0007E4 AF F0            [24]  132 	mov	r7,b
                                    133 ;	circular_buffer.c:6: return (buf->writeIndex - buf->readIndex);
      0007E6 74 04            [12]  134 	mov	a,#0x04
      0007E8 2D               [12]  135 	add	a,r5
      0007E9 FA               [12]  136 	mov	r2,a
      0007EA E4               [12]  137 	clr	a
      0007EB 3E               [12]  138 	addc	a,r6
      0007EC FB               [12]  139 	mov	r3,a
      0007ED 8F 04            [24]  140 	mov	ar4,r7
      0007EF 8A 82            [24]  141 	mov	dpl,r2
      0007F1 8B 83            [24]  142 	mov	dph,r3
      0007F3 8C F0            [24]  143 	mov	b,r4
      0007F5 12 0E D8         [24]  144 	lcall	__gptrget
      0007F8 FA               [12]  145 	mov	r2,a
      0007F9 74 03            [12]  146 	mov	a,#0x03
      0007FB 2D               [12]  147 	add	a,r5
      0007FC FD               [12]  148 	mov	r5,a
      0007FD E4               [12]  149 	clr	a
      0007FE 3E               [12]  150 	addc	a,r6
      0007FF FE               [12]  151 	mov	r6,a
      000800 8D 82            [24]  152 	mov	dpl,r5
      000802 8E 83            [24]  153 	mov	dph,r6
      000804 8F F0            [24]  154 	mov	b,r7
      000806 12 0E D8         [24]  155 	lcall	__gptrget
      000809 FD               [12]  156 	mov	r5,a
      00080A EA               [12]  157 	mov	a,r2
      00080B C3               [12]  158 	clr	c
      00080C 9D               [12]  159 	subb	a,r5
      00080D F5 82            [12]  160 	mov	dpl,a
      00080F 22               [24]  161 	ret
                                    162 ;------------------------------------------------------------
                                    163 ;Allocation info for local variables in function 'empty'
                                    164 ;------------------------------------------------------------
                                    165 ;buf                       Allocated to registers r5 r6 r7 
                                    166 ;------------------------------------------------------------
                                    167 ;	circular_buffer.c:9: bool empty(CircularBuffer_t *buf) {
                                    168 ;	-----------------------------------------
                                    169 ;	 function empty
                                    170 ;	-----------------------------------------
      000810                        171 _empty:
      000810 AD 82            [24]  172 	mov	r5,dpl
      000812 AE 83            [24]  173 	mov	r6,dph
      000814 AF F0            [24]  174 	mov	r7,b
                                    175 ;	circular_buffer.c:10: return (buf->readIndex == buf->writeIndex);
      000816 74 03            [12]  176 	mov	a,#0x03
      000818 2D               [12]  177 	add	a,r5
      000819 FA               [12]  178 	mov	r2,a
      00081A E4               [12]  179 	clr	a
      00081B 3E               [12]  180 	addc	a,r6
      00081C FB               [12]  181 	mov	r3,a
      00081D 8F 04            [24]  182 	mov	ar4,r7
      00081F 8A 82            [24]  183 	mov	dpl,r2
      000821 8B 83            [24]  184 	mov	dph,r3
      000823 8C F0            [24]  185 	mov	b,r4
      000825 12 0E D8         [24]  186 	lcall	__gptrget
      000828 FA               [12]  187 	mov	r2,a
      000829 74 04            [12]  188 	mov	a,#0x04
      00082B 2D               [12]  189 	add	a,r5
      00082C FD               [12]  190 	mov	r5,a
      00082D E4               [12]  191 	clr	a
      00082E 3E               [12]  192 	addc	a,r6
      00082F FE               [12]  193 	mov	r6,a
      000830 8D 82            [24]  194 	mov	dpl,r5
      000832 8E 83            [24]  195 	mov	dph,r6
      000834 8F F0            [24]  196 	mov	b,r7
      000836 12 0E D8         [24]  197 	lcall	__gptrget
      000839 FD               [12]  198 	mov	r5,a
      00083A EA               [12]  199 	mov	a,r2
      00083B B5 05 02         [24]  200 	cjne	a,ar5,00103$
      00083E D3               [12]  201 	setb	c
      00083F 22               [24]  202 	ret
      000840                        203 00103$:
      000840 C3               [12]  204 	clr	c
      000841 22               [24]  205 	ret
                                    206 ;------------------------------------------------------------
                                    207 ;Allocation info for local variables in function 'full'
                                    208 ;------------------------------------------------------------
                                    209 ;buf                       Allocated to registers r5 r6 r7 
                                    210 ;------------------------------------------------------------
                                    211 ;	circular_buffer.c:13: bool full(CircularBuffer_t *buf) {
                                    212 ;	-----------------------------------------
                                    213 ;	 function full
                                    214 ;	-----------------------------------------
      000842                        215 _full:
                                    216 ;	circular_buffer.c:14: return size(buf) == buf->maxBufferLength;
      000842 AD 82            [24]  217 	mov	r5,dpl
      000844 AE 83            [24]  218 	mov	r6,dph
      000846 AF F0            [24]  219 	mov	r7,b
      000848 C0 07            [24]  220 	push	ar7
      00084A C0 06            [24]  221 	push	ar6
      00084C C0 05            [24]  222 	push	ar5
      00084E 12 07 E0         [24]  223 	lcall	_size
      000851 AC 82            [24]  224 	mov	r4,dpl
      000853 D0 05            [24]  225 	pop	ar5
      000855 D0 06            [24]  226 	pop	ar6
      000857 D0 07            [24]  227 	pop	ar7
      000859 74 05            [12]  228 	mov	a,#0x05
      00085B 2D               [12]  229 	add	a,r5
      00085C FD               [12]  230 	mov	r5,a
      00085D E4               [12]  231 	clr	a
      00085E 3E               [12]  232 	addc	a,r6
      00085F FE               [12]  233 	mov	r6,a
      000860 8D 82            [24]  234 	mov	dpl,r5
      000862 8E 83            [24]  235 	mov	dph,r6
      000864 8F F0            [24]  236 	mov	b,r7
      000866 12 0E D8         [24]  237 	lcall	__gptrget
      000869 FD               [12]  238 	mov	r5,a
      00086A EC               [12]  239 	mov	a,r4
      00086B B5 05 02         [24]  240 	cjne	a,ar5,00103$
      00086E D3               [12]  241 	setb	c
      00086F 22               [24]  242 	ret
      000870                        243 00103$:
      000870 C3               [12]  244 	clr	c
      000871 22               [24]  245 	ret
                                    246 ;------------------------------------------------------------
                                    247 ;Allocation info for local variables in function 'mask'
                                    248 ;------------------------------------------------------------
                                    249 ;val                       Allocated with name '_mask_PARM_2'
                                    250 ;buf                       Allocated to registers r5 r6 r7 
                                    251 ;------------------------------------------------------------
                                    252 ;	circular_buffer.c:17: uint8_t mask(CircularBuffer_t *buf, uint8_t val) {
                                    253 ;	-----------------------------------------
                                    254 ;	 function mask
                                    255 ;	-----------------------------------------
      000872                        256 _mask:
      000872 AD 82            [24]  257 	mov	r5,dpl
      000874 AE 83            [24]  258 	mov	r6,dph
      000876 AF F0            [24]  259 	mov	r7,b
                                    260 ;	circular_buffer.c:18: return val & (buf->maxBufferLength - 1);
      000878 74 05            [12]  261 	mov	a,#0x05
      00087A 2D               [12]  262 	add	a,r5
      00087B FD               [12]  263 	mov	r5,a
      00087C E4               [12]  264 	clr	a
      00087D 3E               [12]  265 	addc	a,r6
      00087E FE               [12]  266 	mov	r6,a
      00087F 8D 82            [24]  267 	mov	dpl,r5
      000881 8E 83            [24]  268 	mov	dph,r6
      000883 8F F0            [24]  269 	mov	b,r7
      000885 12 0E D8         [24]  270 	lcall	__gptrget
      000888 14               [12]  271 	dec	a
      000889 55 7B            [12]  272 	anl	a,_mask_PARM_2
      00088B F5 82            [12]  273 	mov	dpl,a
      00088D 22               [24]  274 	ret
                                    275 ;------------------------------------------------------------
                                    276 ;Allocation info for local variables in function 'push'
                                    277 ;------------------------------------------------------------
                                    278 ;data                      Allocated with name '_push_PARM_2'
                                    279 ;buf                       Allocated with name '_push_buf_1_15'
                                    280 ;------------------------------------------------------------
                                    281 ;	circular_buffer.c:21: bool push(CircularBuffer_t *buf, uint8_t data) {
                                    282 ;	-----------------------------------------
                                    283 ;	 function push
                                    284 ;	-----------------------------------------
      00088E                        285 _push:
                                    286 ;	circular_buffer.c:22: if(full(buf))
      00088E 85 82 5D         [24]  287 	mov	_push_buf_1_15,dpl
      000891 85 83 5E         [24]  288 	mov	(_push_buf_1_15 + 1),dph
      000894 85 F0 5F         [24]  289 	mov	(_push_buf_1_15 + 2),b
      000897 12 08 42         [24]  290 	lcall	_full
      00089A 50 02            [24]  291 	jnc	00102$
                                    292 ;	circular_buffer.c:23: return false;
      00089C C3               [12]  293 	clr	c
      00089D 22               [24]  294 	ret
      00089E                        295 00102$:
                                    296 ;	circular_buffer.c:25: buf->array[mask(buf, buf->writeIndex++)] = data;
      00089E 85 5D 82         [24]  297 	mov	dpl,_push_buf_1_15
      0008A1 85 5E 83         [24]  298 	mov	dph,(_push_buf_1_15 + 1)
      0008A4 85 5F F0         [24]  299 	mov	b,(_push_buf_1_15 + 2)
      0008A7 12 0E D8         [24]  300 	lcall	__gptrget
      0008AA FA               [12]  301 	mov	r2,a
      0008AB A3               [24]  302 	inc	dptr
      0008AC 12 0E D8         [24]  303 	lcall	__gptrget
      0008AF FB               [12]  304 	mov	r3,a
      0008B0 A3               [24]  305 	inc	dptr
      0008B1 12 0E D8         [24]  306 	lcall	__gptrget
      0008B4 FC               [12]  307 	mov	r4,a
      0008B5 74 04            [12]  308 	mov	a,#0x04
      0008B7 25 5D            [12]  309 	add	a,_push_buf_1_15
      0008B9 F8               [12]  310 	mov	r0,a
      0008BA E4               [12]  311 	clr	a
      0008BB 35 5E            [12]  312 	addc	a,(_push_buf_1_15 + 1)
      0008BD F9               [12]  313 	mov	r1,a
      0008BE AF 5F            [24]  314 	mov	r7,(_push_buf_1_15 + 2)
      0008C0 88 82            [24]  315 	mov	dpl,r0
      0008C2 89 83            [24]  316 	mov	dph,r1
      0008C4 8F F0            [24]  317 	mov	b,r7
      0008C6 12 0E D8         [24]  318 	lcall	__gptrget
      0008C9 FE               [12]  319 	mov	r6,a
      0008CA 04               [12]  320 	inc	a
      0008CB 88 82            [24]  321 	mov	dpl,r0
      0008CD 89 83            [24]  322 	mov	dph,r1
      0008CF 8F F0            [24]  323 	mov	b,r7
      0008D1 12 0C DF         [24]  324 	lcall	__gptrput
      0008D4 8E 7B            [24]  325 	mov	_mask_PARM_2,r6
      0008D6 85 5D 82         [24]  326 	mov	dpl,_push_buf_1_15
      0008D9 85 5E 83         [24]  327 	mov	dph,(_push_buf_1_15 + 1)
      0008DC 85 5F F0         [24]  328 	mov	b,(_push_buf_1_15 + 2)
      0008DF C0 04            [24]  329 	push	ar4
      0008E1 C0 03            [24]  330 	push	ar3
      0008E3 C0 02            [24]  331 	push	ar2
      0008E5 12 08 72         [24]  332 	lcall	_mask
      0008E8 AF 82            [24]  333 	mov	r7,dpl
      0008EA D0 02            [24]  334 	pop	ar2
      0008EC D0 03            [24]  335 	pop	ar3
      0008EE D0 04            [24]  336 	pop	ar4
      0008F0 EF               [12]  337 	mov	a,r7
      0008F1 2A               [12]  338 	add	a,r2
      0008F2 FA               [12]  339 	mov	r2,a
      0008F3 E4               [12]  340 	clr	a
      0008F4 3B               [12]  341 	addc	a,r3
      0008F5 FB               [12]  342 	mov	r3,a
      0008F6 8A 82            [24]  343 	mov	dpl,r2
      0008F8 8B 83            [24]  344 	mov	dph,r3
      0008FA 8C F0            [24]  345 	mov	b,r4
      0008FC E5 5C            [12]  346 	mov	a,_push_PARM_2
      0008FE 12 0C DF         [24]  347 	lcall	__gptrput
                                    348 ;	circular_buffer.c:26: return true;
      000901 D3               [12]  349 	setb	c
      000902 22               [24]  350 	ret
                                    351 ;------------------------------------------------------------
                                    352 ;Allocation info for local variables in function 'pop'
                                    353 ;------------------------------------------------------------
                                    354 ;data                      Allocated with name '_pop_PARM_2'
                                    355 ;buf                       Allocated with name '_pop_buf_1_17'
                                    356 ;sloc0                     Allocated with name '_pop_sloc0_1_0'
                                    357 ;------------------------------------------------------------
                                    358 ;	circular_buffer.c:29: bool pop(CircularBuffer_t *buf, uint8_t *data) {
                                    359 ;	-----------------------------------------
                                    360 ;	 function pop
                                    361 ;	-----------------------------------------
      000903                        362 _pop:
                                    363 ;	circular_buffer.c:30: if(empty(buf))
      000903 85 82 63         [24]  364 	mov	_pop_buf_1_17,dpl
      000906 85 83 64         [24]  365 	mov	(_pop_buf_1_17 + 1),dph
      000909 85 F0 65         [24]  366 	mov	(_pop_buf_1_17 + 2),b
      00090C 12 08 10         [24]  367 	lcall	_empty
      00090F 50 02            [24]  368 	jnc	00102$
                                    369 ;	circular_buffer.c:31: return false;
      000911 C3               [12]  370 	clr	c
      000912 22               [24]  371 	ret
      000913                        372 00102$:
                                    373 ;	circular_buffer.c:33: *data = buf->array[mask(buf, buf->readIndex++)];
      000913 AA 60            [24]  374 	mov	r2,_pop_PARM_2
      000915 AB 61            [24]  375 	mov	r3,(_pop_PARM_2 + 1)
      000917 AC 62            [24]  376 	mov	r4,(_pop_PARM_2 + 2)
      000919 85 63 82         [24]  377 	mov	dpl,_pop_buf_1_17
      00091C 85 64 83         [24]  378 	mov	dph,(_pop_buf_1_17 + 1)
      00091F 85 65 F0         [24]  379 	mov	b,(_pop_buf_1_17 + 2)
      000922 12 0E D8         [24]  380 	lcall	__gptrget
      000925 F5 66            [12]  381 	mov	_pop_sloc0_1_0,a
      000927 A3               [24]  382 	inc	dptr
      000928 12 0E D8         [24]  383 	lcall	__gptrget
      00092B F5 67            [12]  384 	mov	(_pop_sloc0_1_0 + 1),a
      00092D A3               [24]  385 	inc	dptr
      00092E 12 0E D8         [24]  386 	lcall	__gptrget
      000931 F5 68            [12]  387 	mov	(_pop_sloc0_1_0 + 2),a
      000933 74 03            [12]  388 	mov	a,#0x03
      000935 25 63            [12]  389 	add	a,_pop_buf_1_17
      000937 FD               [12]  390 	mov	r5,a
      000938 E4               [12]  391 	clr	a
      000939 35 64            [12]  392 	addc	a,(_pop_buf_1_17 + 1)
      00093B FE               [12]  393 	mov	r6,a
      00093C AF 65            [24]  394 	mov	r7,(_pop_buf_1_17 + 2)
      00093E 8D 82            [24]  395 	mov	dpl,r5
      000940 8E 83            [24]  396 	mov	dph,r6
      000942 8F F0            [24]  397 	mov	b,r7
      000944 12 0E D8         [24]  398 	lcall	__gptrget
      000947 F9               [12]  399 	mov	r1,a
      000948 04               [12]  400 	inc	a
      000949 8D 82            [24]  401 	mov	dpl,r5
      00094B 8E 83            [24]  402 	mov	dph,r6
      00094D 8F F0            [24]  403 	mov	b,r7
      00094F 12 0C DF         [24]  404 	lcall	__gptrput
      000952 89 7B            [24]  405 	mov	_mask_PARM_2,r1
      000954 85 63 82         [24]  406 	mov	dpl,_pop_buf_1_17
      000957 85 64 83         [24]  407 	mov	dph,(_pop_buf_1_17 + 1)
      00095A 85 65 F0         [24]  408 	mov	b,(_pop_buf_1_17 + 2)
      00095D C0 04            [24]  409 	push	ar4
      00095F C0 03            [24]  410 	push	ar3
      000961 C0 02            [24]  411 	push	ar2
      000963 12 08 72         [24]  412 	lcall	_mask
      000966 AF 82            [24]  413 	mov	r7,dpl
      000968 D0 02            [24]  414 	pop	ar2
      00096A D0 03            [24]  415 	pop	ar3
      00096C D0 04            [24]  416 	pop	ar4
      00096E EF               [12]  417 	mov	a,r7
      00096F 25 66            [12]  418 	add	a,_pop_sloc0_1_0
      000971 FF               [12]  419 	mov	r7,a
      000972 E4               [12]  420 	clr	a
      000973 35 67            [12]  421 	addc	a,(_pop_sloc0_1_0 + 1)
      000975 FE               [12]  422 	mov	r6,a
      000976 AD 68            [24]  423 	mov	r5,(_pop_sloc0_1_0 + 2)
      000978 8F 82            [24]  424 	mov	dpl,r7
      00097A 8E 83            [24]  425 	mov	dph,r6
      00097C 8D F0            [24]  426 	mov	b,r5
      00097E 12 0E D8         [24]  427 	lcall	__gptrget
      000981 8A 82            [24]  428 	mov	dpl,r2
      000983 8B 83            [24]  429 	mov	dph,r3
      000985 8C F0            [24]  430 	mov	b,r4
      000987 12 0C DF         [24]  431 	lcall	__gptrput
                                    432 ;	circular_buffer.c:34: return true;
      00098A D3               [12]  433 	setb	c
      00098B 22               [24]  434 	ret
                                    435 	.area CSEG    (CODE)
                                    436 	.area CONST   (CODE)
                                    437 	.area XINIT   (CODE)
                                    438 	.area CABS    (ABS,CODE)
